// lt31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {

		if (nums.size() <= 1)
			return;

		int j = nums.size() - 2;
		for ( ; j >= 0; --j) {
			if (nums[j] < nums[j+1])
				break;			
		}
		if (j == -1) {
			sort(nums.begin(), nums.end());
			return;
		}

		auto ref = nums[j];
		int minOut = INT_MAX, mi;
		for (auto k = nums.size() - 1; k > j; --k) {
			auto out = nums[k];
			if (out > ref && out < minOut) {
				minOut = out;
				mi = k;
			}
		}

		swap(nums[j], nums[mi]);
		sort(nums.begin() + j + 1, nums.end());
	}
};

int main()
{
	vector<int> v({ 1,1 });
	Solution s;
	s.nextPermutation(v);
	for (auto val : v) {
		cout << val << " ";
	}
	cout << endl;

    return 0;
}

