// lt27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int value) {

		unsigned int rd = 0, wr = 0;

		for (; rd < nums.size(); ++rd) {
			if ( (nums[rd] != value) )
				nums[wr++] = nums[rd];
		}

		return wr;
	}
};

int main()
{
	Solution s;
	vector<int> v({ 3, 2, 2, 3 });
	auto ns = s.removeElement(v, 3);
	for (auto i = 0; i < ns; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

