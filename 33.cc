// lt33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
	int bs(vector<int>& nums, int target, int low, int high) 
	{
		if (low > high) {
			return -1;
		}
		
		auto mid = low + (high - low) / 2;
		
		if (nums[mid] == target) {
			return mid;
		} else if (target < nums[mid]) {
			return bs(nums, target, low, mid - 1);
		} else {
			return bs(nums, target, mid +1, high);
		}
	}

	int getDip(vector<int>& nums, int low, int high)
	{
		auto mid = low + (high - low) / 2;
     
		if (high <= low) {
			return low;
		} else if (nums[mid] > nums[mid + 1]) {
			return mid + 1;
		} else if (nums[mid] < nums[low]) {
			return getDip(nums, low, mid);
		} else if (nums[mid] > nums[high]) {
			return getDip(nums, mid, high);
		} else {
			return 0;
		}
	}

public:
	int search(vector<int>& nums, int target) 
	{
		int dip = getDip(nums, 0, nums.size() - 1);
		cout << "dip:" << dip << endl;
		if (dip == 0) {
			return bs(nums, target, 0, nums.size() - 1);
		}

		auto left = bs(nums, target, 0, dip - 1);
		cout << "left:" << left << endl;
		if (left != -1) {
			return left;
		}

		auto right = bs(nums, target, dip, nums.size() - 1);
		cout << "right:" << right << endl;
		if (right != -1) {
			return right;
		}

		return -1;
	}
};

int main()
{
	vector<int> v({ 4,5,6,7,0,1,2 });
	Solution s;
	cout << s.search(v, 1) << endl;
	cout << s.search(v, 8) << endl;
	cout << s.search(v, 4) << endl;
	return 0;
}

