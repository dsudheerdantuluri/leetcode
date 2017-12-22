// 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int getNew(int sum, unsigned int dv)
	{
		if (sum > INT_MAX / 10) {
			return INT_MAX;
		}


		sum *= 10;
		if (sum > (INT_MAX - dv)) {
			return INT_MAX;
		}

	}

	int myAtoi(string str) {
	
		auto sum = 0;
		bool nwscf = false;
		auto sign = 1;
		auto ss = false;
		auto th = INT_MAX;
		for (auto c : str) {
			
			if ( (!nwscf && isspace(c)) ) {				
				continue;
			} 
			
			nwscf = true;
			
			if ( !ss && (c == '-')) {				
				sign = -1;
				th = INT_MIN;
				ss = true;
				continue;
			}
			
			if ( !ss && (c == '+') ) {
				sign = +1;
				ss = true;
				continue;
			}

			if (!isdigit(c)) {
				break;
			}

			ss = true;
			auto dv = (c - '0');			
				
			if ( sum > (INT_MAX / 10) ) {
				sum = (sign == 1) ? INT_MAX : INT_MIN;
				break;
			}

			sum *= 10;

			if ( (sign == 1) && (sum > (INT_MAX - dv)) ) {
				return INT_MAX;
			}
			if ( (sign == -1) && (sum - 1) > (INT_MAX - dv) ) {
				return INT_MIN;
			}
			sum += dv;

		}
		
		sum = sum*sign;
		return sum;
	}
};

int main()
{	
	Solution s;
	cout << s.myAtoi("123") << endl;
	cout << s.myAtoi(" 245") << endl;
	cout << s.myAtoi(" 24 5") << endl;
	cout << s.myAtoi(" 2 4 5") << endl;
	cout << s.myAtoi("-980") << endl;
	cout << s.myAtoi("+100") << endl;
	cout << s.myAtoi("     -980") << endl;
	cout << s.myAtoi("   +100") << endl;
	cout << s.myAtoi("   +57 das9d0 3") << endl;
	cout << s.myAtoi("  570000 das9d0 3") << endl;
	cout << s.myAtoi("  011 das9d0 3") << endl;
	cout << s.myAtoi("  ") << endl;
	cout << s.myAtoi("sudheer") << endl;
	cout << s.myAtoi("+-2") << endl;
	cout << s.myAtoi("2147483648") << endl;
	cout << s.myAtoi("9223372036854775809") << endl;
	cout << s.myAtoi("-9223372036854775809") << endl;
	//cout << INT_MAX << endl;
    return 0;
}

