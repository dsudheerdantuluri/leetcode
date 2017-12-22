// lt26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		
		unsigned int rd = 0, wr = 0;

		for (; rd < nums.size(); ++rd) {
			if ((rd == 0) || (nums[rd] > nums[rd - 1]))
				nums[wr++] = nums[rd];
		}
	
		return wr;
	}
};

int main()
{
	Solution s;
	vector<int> v({ 1,1,2 });
	auto ns = s.removeDuplicates(v);
	for (auto i = 0; i < ns; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

    return 0;
}

