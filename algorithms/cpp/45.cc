// lt45.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {

		if (nums.size() <= 1) {
			return 0;
		}

		auto maxIndex = nums[0];
		auto maxPos = nums[0];
		auto steps = 1;

		if (maxIndex >= nums.size() - 1) {
			return 1;
		}

		for (int i = 1; i < nums.size() - 1; ++i) {			
			if (maxIndex >= i) {
				if (i + nums[i] > maxIndex) {
					maxIndex = i + nums[i];
					
				}
				if (i == maxPos) {
					++steps;
					maxPos = maxIndex;
				}
			} else {
				return 0;
			}
		}

		if (maxIndex >= nums.size() - 1) {
			return steps;
		} else {
			return 0;
		}

	}

};

int main()
{
	Solution s;
	vector<int> v{ 2,3,1,1,4 };
	cout << s.jump(v) << endl;
	vector<int> v1{ 4,1,1,3,1,1,1 };
	cout << s.jump(v1) << endl;
    return 0;
}

