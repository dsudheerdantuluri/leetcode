// lt44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		
		vector<vector<bool>> match(s.length() + 1, vector<bool>(p.length() + 1, false));

		//empty string - empty pattern
		match[0][0] = true;

		//empty string - non-empty pattern
		bool m = false;
		auto p_nonstar = p.find_first_not_of('*');
		for (auto j = 1; j <= p.length(); ++j) {
			match[0][j] = p_nonstar == string::npos ? true : j <= p_nonstar ? true : false;
		}

		//non-empty string - empty pattern
		for (auto i = 1; i <= s.length(); ++i) {
			match[i][0] = false;
		}

		//non-empty string non-empty pattern
		for (auto i = 1; i <= s.length(); ++i) {
			for (auto j = 1; j <= p.length(); ++j) {
				if (p[j - 1] != '*') {
					match[i][j] = match[i - 1][j - 1] && ((s[i - 1] == p[j - 1]) || (p[j - 1] == '?'));
				} else {
					match[i][j] = match[i][j - 1] || match[i-1][j];
				}					              
			}
		}

		return match[s.length()][p.length()];
	}
};

int main()
{
	Solution s;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aaa", "a") << endl;
	cout << s.isMatch("aa", "*") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", "?*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;

	cout << s.isMatch("aaaa", "***a") << endl;
    return 0;
}

