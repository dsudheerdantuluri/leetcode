// lt18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		set<vector<int>> result;
		if (nums.size() < 4) {
			return vector<vector<int>>();
		}

		unordered_multimap<int, pair<int, int>> twoSumMap;
		for (auto i = 0; i < nums.size() - 1; ++i) {
			for (auto j = i + 1; j < nums.size(); ++j) {
				pair<int, int> p(i, j);
				auto sum = nums[i] + nums[j];
				twoSumMap.insert(pair<int, pair<int, int>>(sum, p));
			}
		}

		for (auto i = 0; i < nums.size() - 1; ++i) {
			for (auto j = i + 1; j < nums.size(); ++j) {
				auto remSum = target - (nums[i] + nums[j]);
				auto foundIt = twoSumMap.equal_range(remSum);
				for ( auto it = foundIt.first ; it != foundIt.second ; ++it ) {
					auto k = it->second.first;
					auto l = it->second.second;
					if (!(k == i || k == j || l == i || l == j)) {
						vector<int> v({ nums[i], nums[j], nums[k], nums[l] });
						sort(v.begin(), v.end());
						result.insert(v);
					}
				}				
			}
		}

		return vector<vector<int>>(result.begin(), result.end());
	}
};

int main()
{
	Solution s;
	vector<int> v({ 1,0,-1,0,-2,2 });
	auto vecVecInt = s.fourSum(v, 0);
	for (auto vecInt : vecVecInt) {
		for (auto i : vecInt) {
			cout << i << " ";
		}
		cout << endl;
	}
    return 0;
}

