#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		unordered_map<int, unordered_set<int>> pg; 
		for (const auto &p : prerequisites) pg[p.first].insert(p.second);
		vector<bool> track(numCourses, false);
		vector<bool> seen(numCourses, false);
		for (const auto &p : prerequisites) {
			if ((!seen[p.first]) && hasCycle(p.first, seen, track, pg)) return false;
		}   
		return true;
	}   
	bool hasCycle(int s, vector<bool> &seen, vector<bool> &track, unordered_map<int, unordered_set<int>> &pg)  {
		if (track[s]) return true;
		if (seen[s]) return false;
		seen[s] = track[s] = true;
		unordered_set<int> &dv = pg[s];
		for (auto d: dv) {
			if (hasCycle(d, seen, track, pg)) {
				track[s] = false;
				return true;
			}
		}   
		track[s] = false;
		return false;
	}   
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<int> result, heap;
		if (!canFinish(numCourses, prerequisites)) return result;
		unordered_map<int, unordered_set<int>> pg;
		vector<int> indegree(numCourses, 0);
		for (const auto &p : prerequisites) {
			pg[p.second].insert(p.first);
			++indegree[p.first];
		}
		for (int i=0; i < numCourses; ++i)
			heap.push_back(i);
		auto cmp = [&indegree](int i, int j) { return indegree[i] > indegree[j]; };
		while (heap.size() > 0) {
			make_heap(heap.begin(), heap.end(), cmp);
			auto index = heap.front();
			result.push_back(index);	
			auto git = pg.find(index);
			if (git != pg.end()) {
				for (auto d: git->second)
					--indegree[d];
				git->second.clear();
			}
			pop_heap(heap.begin(), heap.end());heap.pop_back();
		}	
		return result; 
	}
};


int main()
{
	Solution s;
	vector<pair<int, int>> v{{1,0},{2,1}};	
	for (auto val : s.findOrder(3,v)) cout << val << " ";
	cout << endl;
	return 0;
}
