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
	int threeSumClosest(vector<int>& nums, int target) {

		if (nums.size() < 3) {
			return 0;
		}

		std::sort(nums.begin(), nums.end());

		int distance = INT_MAX;
		int closest3Sum = nums[0] + nums[1] + nums[2];

		for (auto i = 0; i < nums.size(); ++i) {
			auto c = nums[i];
			unsigned int low = 0, high = nums.size() - 1;
			while (low < high) {
				if (i == low) {
					low++;
					continue;
				}
				else if (i == high) {
					high--;
					continue;
				}
				else {
					auto a = nums[low];
					auto b = nums[high];
					auto aPlusBPlusC = a + b + c;
					if (aPlusBPlusC == target) {
						low++; high--;
						return target;
					}
					else if (aPlusBPlusC < target) {
						low++;
					}
					else {
						high--;
					}

					auto minDistance = abs(aPlusBPlusC - target);
					if (distance > minDistance) {
						distance = minDistance;
						closest3Sum = aPlusBPlusC;
					}
				}

			}
		}

		return closest3Sum;
	}
};

int main()
{
	Solution s;
	vector<int> v({ -1, 2, 1, -4 });
	cout << s.threeSumClosest(v, 1) << endl;	
	return 0;
}

