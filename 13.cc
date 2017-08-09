// 13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {

		std::map<std::string, int> ri
		{
			make_pair<string, int>("M", 1000),
			make_pair<string, int>("D", 500),
			make_pair<string, int>("C", 100),
			make_pair<string, int>("L", 50),
			make_pair<string, int>("X", 10),
			make_pair<string, int>("V", 5),
			make_pair<string, int>("I", 1)
		};

		auto sum = 0;
		auto prev = 0;

		for (auto i = 0; i < s.size(); ++i) {
			auto r = s.substr(i, 1);
			auto val = ri[r];
			sum += val;
			if ( (prev != 0) && (prev < val) ) {
				sum -= 2 * prev;
			}
			prev = val;
			//cout << "sum:" << sum << endl;
		}

		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.romanToInt("MMMCMXCIX") << endl;
    return 0;
}

