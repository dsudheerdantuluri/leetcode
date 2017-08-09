// 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindromeRec(int x, int &xc)
	{
		if (x / 10 == 0) {
			return (x == xc % 10);
		}

		if (!isPalindromeRec(x/10, xc)) {
			return false;
		}

		xc = xc / 10;

		return (x % 10 == xc % 10);
	}

	bool isPalindrome(int x) {
		x = (x > 0) ? x : -x;
		auto xc = x;
		return isPalindromeRec(x, xc);
	}
};

int main()
{
	Solution s;
	
	cout << s.isPalindrome(1) << endl;
	cout << s.isPalindrome(12) << endl;
	cout << s.isPalindrome(123) << endl;
	cout << s.isPalindrome(121) << endl;
	cout << s.isPalindrome(1221) << endl;


	cout << s.isPalindrome(-1) << endl;
	cout << s.isPalindrome(-12) << endl;
	cout << s.isPalindrome(-123) << endl;
	cout << s.isPalindrome(-121) << endl;
	cout << s.isPalindrome(-1221) << endl;

	cout << s.isPalindrome(-2147447412) << endl;	
	
	cout << s.isPalindrome(1000001) << endl;
	

	return 0;
}

