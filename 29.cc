// lt29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}

		bool neg = ( (dividend > 0) ^ (divisor > 0) );
		dividend = -abs(dividend);
		divisor = -abs(divisor);

		auto ud = divisor;
		auto t = 1;
		auto q = 0;
		while (dividend <= divisor) {
			dividend -= ud;
			q += t;
			if (ud < (INT_MIN - ud)) {
				continue;
			}
			ud = ud + ud;
			t = t + t;
			if (dividend > ud) {
				ud = divisor;
				t = 1;
			}
		}

		return neg ? -q : q;
	}
};

int main()
{
	Solution s;
	cout << s.divide(10, 1) << endl;
	cout << s.divide(10, 2) << endl;
	cout << s.divide(10, 3) << endl;
	cout << s.divide(10, 4) << endl;
	cout << s.divide(10, 5) << endl;
	cout << s.divide(10, 6) << endl;
	cout << s.divide(10, 7) << endl;
	cout << s.divide(10, 8) << endl;
	cout << s.divide(10, 9) << endl;
	cout << s.divide(10, 10) << endl;
	cout << s.divide(10, 11) << endl;
	cout << s.divide(1, INT_MAX) << endl;
	cout << s.divide(INT_MAX, 1) << endl;
	cout << s.divide(INT_MAX, INT_MAX) << endl;
	cout << s.divide(INT_MIN, 1) << endl;
	cout << s.divide(-10, 1) << endl;
	cout << s.divide(-10, 2) << endl;
	cout << s.divide(-10, 3) << endl;
	cout << s.divide(-10, 4) << endl;
	cout << s.divide(-10, 5) << endl;
	cout << s.divide(-10, 6) << endl;
	cout << s.divide(-10, 7) << endl;
	cout << s.divide(-10, 8) << endl;
	cout << s.divide(-10, 9) << endl;
	cout << s.divide(-10, -10) << endl;
	cout << s.divide(-10, 11) << endl;

	cout << s.divide(INT_MIN, -1) << endl;
    return 0;
}

