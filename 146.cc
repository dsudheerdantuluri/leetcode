#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {

private:
		int m_capacity;
		int m_size;
		list<pair<int,int>> l;
		unordered_map<int,list<pair<int,int>>::iterator> h;

public:
    LRUCache(int capacity) : m_capacity(capacity), m_size(0) {}
 
    int get(int key) 
		{
		 auto it = h.find(key);
		 if (it == h.end()) return -1;
		 auto val = it->second->second;
		 l.splice(l.begin(), l, it->second);
		 return val;       
    }
    
    void put(int key, int value) 
		{
		 	auto it = h.find(key);
      if (it != h.end()) {
				it->second->second = value;
		 		l.splice(l.begin(), l, it->second);
			} else {
				if (m_size == m_capacity) {
					h.erase(h.find(l.back().first));
					l.pop_back();
					--m_size;
				}
				l.push_front(make_pair(key,value));
				h[key] = l.begin();
				++m_size;
			}
    }

		void print()
		{
		  for (auto v:l) cout << v.first << "," << v.second << " ";
		  cout << endl;
		}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
	LRUCache cache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.print();
	cache.put(2, 2);
	cache.print();
	cout << cache.get(1) << endl;       // returns 1
	cache.print();
	cache.put(3, 3);    // evicts key 2
	cache.print();
	cout << cache.get(2) << endl;       // returns -1 (not found)
	cache.print();
	cache.put(4, 4);    // evicts key 1
	cache.print();
	cout << cache.get(1) << endl;       // returns -1 (not found)
	cache.print();
	cout << cache.get(3) << endl;       // returns 3
	cache.print();
	cout << cache.get(4) << endl;       // returns 4
	cache.print();
	return 0;
}
