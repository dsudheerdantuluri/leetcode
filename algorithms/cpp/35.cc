// lt35.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
	int searchInsert(vector<int>& nums, int target, int low, int high) 
	{
		auto mid = low + (high - low) / 2;

		if (high <= low) {
			return target <= nums[low] ? low : low + 1;
		}
		else if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			return searchInsert(nums, target, mid + 1, high);
		}
		else {
			return searchInsert(nums, target, low, mid-1);
		}
	}

public:
	int searchInsert(vector<int>& nums, int target) 
	{
		return searchInsert(nums, target, 0, nums.size() - 1);
	}
};

int main()
{
	Solution s;
	
	vector<int> v1({1,3,5,6});
	cout << s.searchInsert(v1, 5) << endl;
	
	vector<int> v2({ 1,3,5,6 });
	cout << s.searchInsert(v2, 2) << endl;

	vector<int> v3({ 1,3,5,6 });
	cout << s.searchInsert(v3, 7) << endl;

	vector<int> v4({ 1,3,5,6 });
	cout << s.searchInsert(v4, 0) << endl;
    
	return 0;
}

