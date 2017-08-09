// lt38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {

		if (n == 1) {
			return "1";
		}

		string s("");
		string prev = countAndSay(n - 1);
		auto i = 0, count = 0;
		while (i < prev.length()) {
			auto j = i;
			char c = prev[j];
			while (j < prev.length() && prev[j] == c) {
				j++;
				count++;
			}
			s += to_string(count);
			s += string(1, c);
			count = 0;
			i = j;
		}

		return s;
	}
};

int main()
{
	Solution s;
	cout << s.countAndSay(1) << endl;
	cout << s.countAndSay(2) << endl;
	cout << s.countAndSay(3) << endl;
	cout << s.countAndSay(4) << endl;
	cout << s.countAndSay(5) << endl;

    return 0;
}

