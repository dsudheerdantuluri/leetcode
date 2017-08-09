// lt42.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {

		if (height.size() < 3) {
			return 0;
		}

		auto left = 0;
		auto right = height.size() - 1;
		auto maxLeft = 0;
		auto maxRight = 0;
		auto sum = 0;

		while (left < right) {

			if (height[left] <= height[right]) {
				if (maxLeft <= height[left]) {
					maxLeft = height[left];
				} else {
					sum += maxLeft - height[left];
				}
				left++;
			} else {
				if (maxRight <= height[right]) {
					maxRight = height[right];
				} else {
					sum += maxRight - height[right];
				}
				right--;
			}
		}

		return sum;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> v1{ 4,2, 3 };
	cout << s.trap(v) << endl;
	cout << s.trap(v1) << endl;
    return 0;
}

