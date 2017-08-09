// lt28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {

		auto nSz = needle.length();
		auto hSz = haystack.length();

		if (hSz < nSz) {
			return -1;
		}

		auto effHSz = hSz - nSz + 1;
		
		for (auto i = 0; i < effHSz; ++i) {
			auto temp = i, j = 0;
			while ( (i < hSz) && (j < nSz) && (haystack[i] == needle[j]) ) {
				i++;
				j++;
			}
			if (j == nSz) {
				return temp;
			}
			i = temp;
		}

		return -1;
	}
};

int main()
{
	Solution s;
	cout << s.strStr("sudheerd", "sudheer") << endl;
    return 0;
}

