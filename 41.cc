// lt41.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {

		auto i = 0u;
		auto sz = nums.size();

		if (sz == 0) {
			return 1;
		}

		while (i < sz) {
			if ( (nums[i] == i) || (nums[i] < 0) || (nums[i] >= sz) || (nums[i] == nums[nums[i]]) ) {
				++i;
			} else {
				auto temp = nums[i];
				swap(nums[i], nums[temp]);
			}
		}

		for (auto i = 1u; i < sz; ++i) {			
			if (nums[i] != i) {
				return i;
			}
		}

		return sz == nums[0] ? sz+1 : sz;
	}
};

int main()
{
	vector<int> v1{ 1,2,0 };
	vector<int> v2{ 3, 4, -1, 1 };
	vector<int> v3{ 1 };
	vector<int> v4{};
	vector<int> v5{ 1, 1 };
	vector<int> v6{ 2, 1 };
	Solution s;
	cout << s.firstMissingPositive(v1) << endl; 
	cout << s.firstMissingPositive(v2) << endl;
	cout << s.firstMissingPositive(v3) << endl;
	cout << s.firstMissingPositive(v4) << endl;
	cout << s.firstMissingPositive(v5) << endl;
	cout << s.firstMissingPositive(v6) << endl;
    return 0;
}

