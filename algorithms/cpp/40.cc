// lt39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
	
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
		vector<vector<vector<vector<int>>>> subsets(target+1);
		vector<vector<vector<int>>> sd(candidates.size(), vector<vector<int>>());
		for (auto i = 0; i <= target; ++i) {
			subsets[i] = sd;
		}
		
		vector<int> empty;
		for (auto j = 0; j < candidates.size(); j++)
			subsets[0][j].emplace_back(empty);

		for (auto i = 1; i <= target; ++i) {
			for (auto j = 0; j <= candidates.size() - 1; ++j) {
				vector<vector<int>> v;
				if (j - 1 >= 0) {
					vector<vector<int>> &p1 = subsets[i][j - 1];
					v.insert(v.end(), p1.begin(), p1.end());
				}
				if ((i - candidates[j] >= 0)) {
					auto old = subsets[i - candidates[j]][j];					
					for (auto &e : old) {
						auto it = find(e.begin(), e.end(), j);
						if (it == e.end()) {
							e.emplace_back(j);
							//sort(e.begin(), e.end());
							v.emplace_back(e);
						}						
					}					
				}
			
				subsets[i][j] = v;
				//set<vector<int>> s(v.begin(),v.end());
				//subsets[i][j] = vector<vector<int>>(s.begin(), s.end());
				/*
				cout << "---------------------------------" << endl;
				cout << i << "," << j << "::" << endl;
				for (auto v2 : subsets[i][j]) {
					for (auto v4 : v2) {
						cout << v4 << " ";
					}
					cout << endl;
				}
				cout << "---------------------------------" << endl;
				*/
			}			
		}

		
		for (auto &v : subsets[target][candidates.size() - 1]) {
			for (auto i = 0; i < v.size(); ++i) {
				v[i] = candidates[v[i]];
			}
			sort(v.begin(), v.end());
		}
		set<vector<int>> s(subsets[target][candidates.size() - 1].begin(), subsets[target][candidates.size() - 1].end());
		return vector<vector<int>>(s.begin(), s.end());
	}
};

#include <time.h>

int main()
{
	clock_t tStart = clock();
	Solution s;
	vector<int> v({ 10, 1, 2, 7, 6, 1, 5 });
	auto v1 = s.combinationSum(v, 8);
	/*vector<int> v({  1 });
	auto v1 = s.combinationSum(v, 2); */
	for (auto v2 : v1) {
		for (auto e : v2) {
			cout << e << " ";
		}
		cout << endl;
	}
	printf("Time taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;
}

