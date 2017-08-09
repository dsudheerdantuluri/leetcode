// lt39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	void combinationSumRec(vector<int>& candidates, int target, int ci, vector<vector<int>> &result, vector<int> &comb)
	{
		if (ci == candidates.size() - 1) {
			if (target%candidates[ci] == 0) {
				comb[ci] = target / candidates[ci];
				vector<int> v;
				for (auto i = 0; i < candidates.size(); ++i ) {
					for (auto j = 0; j < comb[i]; ++j) {
						v.emplace_back(candidates[i]);
					}					
				}
				result.emplace_back(v);
			}
			return;
		}
		
		for (auto k = 0; k <= target / candidates[ci]; ++k) {
			comb[ci] = k;
			combinationSumRec(candidates, target - k * candidates[ci], ci+1, result, comb);
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> comb(candidates.size());
		combinationSumRec(candidates, target, 0, result, comb);
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v({2,3,6,7});
	auto v1 = s.combinationSum(v, 7);
	for (auto v2 : v1) {
		for (auto v : v2) {
			cout << v << " ";
		}
		cout << endl;
	}
    return 0;
}

