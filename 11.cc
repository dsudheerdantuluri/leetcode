// 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {

		if (height.size() == 0) {
			return 0;
		}

		unsigned i = 0u, j = height.size() - 1;
		
		auto maxArea = 0u;
		
		while (i < j) {
			maxArea = max(maxArea, (j - i) * min(height[i], height[j]));
			if (height[i] < height[j]) {
				++i;
			} else {
				--j;
			}
		}

		return maxArea;
	}
};

int main()
{
	//cout << "Hello World" << endl;
	Solution s;
	cout << s.maxArea(vector<int>{ 1,2,3,3,2,1 }) << endl;
    return 0;
}

