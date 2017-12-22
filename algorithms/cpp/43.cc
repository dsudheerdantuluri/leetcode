// lt43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
private:
	string add(string num1, string num2)
	{
		string result;

		int i = 0, j = 0, carry = 0;
		
		for (i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; --i, --j) {
			auto di = num1[i] - '0';
			auto dj = num2[j] - '0';
			auto sum = di + dj + carry;
			result += to_string(sum % 10);
			carry = sum / 10;
		}

		for (auto k = i; k >= 0; --k) {
			auto di = num1[k] - '0';
			result += to_string((di + carry) % 10);
			carry = (di + carry) / 10;
		}

		for (auto k = j; k >= 0; --k) {
			auto dj = num2[k] - '0';
			result += to_string((dj + carry) % 10);
			carry = (dj + carry) / 10;
		}

		if (carry != 0) {
			result += to_string(carry);
		}

		reverse(result.begin(), result.end());

		return result;

	}

	string multiply(string num1, char digit)
	{
		//cout << "multiply:" << num1.c_str() << " " << digit << endl;
		string result("");
		auto d = digit - '0';
		auto prod = 1, carry = 0;

		for (int j = num1.size() - 1; j >= 0; --j) {
			auto sd = num1[j] - '0';
			prod = sd * d;
			auto rem = (prod + carry) % 10;
			carry = (prod + carry)/ 10;
			result += to_string(rem);
		}

		if (carry != 0) {
			result += to_string(carry);
		}

		reverse(result.begin(), result.end());
		//cout << "result:" << result.c_str() << endl;
		return result;
	}

public:
	string multiply(string num1, string num2) 
	{
		if (num1 == "0" || num2 == "0") {
			return "0";
		}

		string product("0"), zero("");

		for (int j = num2.size() - 1; j >= 0; --j) {
			string dp = multiply(num1, num2[j]);
			dp += zero;
			zero += "0";
			//cout << "product:" << product.c_str() << endl;
			//cout << "dp:" << dp.c_str() << endl;
			product = add(product, dp);			
			//cout << "product:" << product.c_str() << endl;
		}

		return product;
	}
};

int main()
{
	Solution s;
	cout << s.multiply("123", "111").c_str() << endl;
	cout << s.multiply("999", "9").c_str() << endl;
	cout << s.multiply("9133", "0").c_str() << endl;
    return 0;
}

