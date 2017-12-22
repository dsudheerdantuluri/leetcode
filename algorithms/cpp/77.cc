#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
		void permute(vector<bool> &on, vector<int> &items, vector<vector<int>> &result, int change)
		{
			if (change == on.size()) {
				vector<int> re;
				for (int i=0; i<on.size(); ++i) {
					if (on[i]) 
						re.emplace_back(items[i]);
				}
				result.emplace_back(re);
			}

		  set<bool> uon;
			for (int i=change; i<on.size(); ++i) {
				if (uon.find(on[i]) == uon.end()) {
					swap(on[change], on[i]);
					permute(on, items, result, change+1);
					swap(on[i], on[change]);
					uon.insert(on[i]);
				}
			}	

		}
public:
    vector<vector<int>> combine(int n, int k) 
		{
			vector<vector<int>> result;
			
			vector<bool> on(n, false);
      for (int i=0; i<k; ++i) 
				on[i] = true;

			vector<int> items;
			for (int i=1; i<=n; ++i)
				items.emplace_back(i);

			permute(on, items, result, 0);

			return result; 
    }
};

int main()
{
	Solution s;
	for (const auto &vi: s.combine(4,2)) {
		for (auto i: vi) {
			cout << i << " ";
		}
		cout << endl;
	}
	
	return 0;
}
