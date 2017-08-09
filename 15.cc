// 15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {

    public:
		vector<vector<int>> threeSum(vector<int>& nums)
		{
			if (nums.size() < 3) {
				return vector<vector<int>>();
			}

			set<vector<int>> allTriplets;

			std::sort(nums.begin(), nums.end());

			std::unordered_set<int> hash(nums.begin(), nums.end());

			for (auto i = 0; i < nums.size(); ++i ) {
				auto c = nums[i];
				unsigned int low = 0, high = nums.size() - 1;
				while (low < high) {					
					if (i == low) {
						low++;
						continue;
					} else if (i == high) {
						high--;
						continue;
					} else {
						auto a = nums[low];
						auto b = nums[high];
						auto aPlusB = a + b;
						if (aPlusB == -c) {
							vector<int> triplet({ a,b,c });
							sort(triplet.begin(), triplet.end());
							allTriplets.insert(triplet);
							low++; high--;
						}
						else if (aPlusB < -c) {
							low++;
						}
						else {
							high--;
						}
					}
				}
			}

			return vector<vector<int>>(allTriplets.begin(), allTriplets.end());
		}
};

int main()
{
	Solution s;
	vector<int> v({ -1, 0, 1, 2, -1, -4 });
	auto ans = s.threeSum(v);
	for (auto vec : ans) {
		for (auto elem : vec) {
			cout << elem << " ";
		}
		cout << endl;
	}
    return 0;
}

