// lt34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
	void searchRangeImplLeft(vector<int>& nums, int target, vector<int> &range, int low, int high)
	{
		auto mid = low + (high - low) / 2;

		if (high < low) {
			range[0] = -1;
		} else if ( nums[mid] == target ) {
			if (nums[low] == target) {
				range[0] = low;
			} else {
				 searchRangeImplLeft(nums, target, range, low+1, mid);
			}
		} else if (nums[mid] > target) {
			 searchRangeImplLeft(nums, target, range, low, mid-1);
		} else {
			 searchRangeImplLeft(nums, target, range, mid+1, high);
		}
	}

	void searchRangeImplRight(vector<int>& nums, int target, vector<int> &range, int low, int high)
	{
		auto mid = low + (high - low) / 2;

		if (high < low) {
			range[1] = -1;
		} else if (nums[mid] == target) {
			if (nums[high] == target) {
				range[1] = high;
			} else {
				searchRangeImplRight(nums, target, range, mid, high-1);
			}
		} else if (nums[mid] > target) {
			searchRangeImplRight(nums, target, range, low, mid - 1);
		} else {
			searchRangeImplRight(nums, target, range, mid + 1, high);
		}
	}

public:
	vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> range(2, -1);

		if (nums.size() == 0) {
			return range;
		}

		searchRangeImplLeft(nums, target, range, 0, nums.size() - 1);
		searchRangeImplRight(nums, target, range, 0, nums.size() - 1);
		return range;
	}
};

int main()
{
	vector<int> v({5,7,7,8,8,10});
	Solution s;
	auto vec = s.searchRange(v, 8);
	for (auto val : vec) {
		cout << val << " ";
	}
	cout << endl;

    return 0;
}

