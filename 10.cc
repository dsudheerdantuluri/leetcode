// 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) 
	{
		auto m = s.length(), n = p.length();
		vector<vector<bool>> f(m+1, vector<bool>(n+1));

		//empty string - empty pattern
		f[0][0] = true;
		
		//non-empty string - empty pattern
		for (auto i = 1; i <= m; ++i) {
			f[i][0] = false;
		}

		//empty string - non-empty pattern
		for (auto j = 1; j <= n; ++j) {
			f[0][j] = (j > 1) && (p[j - 1] == '*') && f[0][j - 2];
		}

		//non-empty string - non-empty pattern
		for (auto i = 1; i <= m; ++i) {
			for (auto j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					f[i][j] = (j>1) && ( (f[i][j-2]) || ( ((s[i-1] == p[j-2]) || (p[j-2] == '.')) && f[i-1][j] ) );
				} else {
					f[i][j] = ((s[i - 1] == p[j - 1]) || (p[j - 1] == '.')) && f[i - 1][j - 1];
				}
			}
		}

		return f[m][n];
	}
};

int main()
{	
	Solution s;
	/*cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "aa") << endl;
	cout << s.isMatch("aaa", "aa") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("aa", ".*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("ab", ".*c") << endl;
	cout << s.isMatch("aaa", "a*a") << endl;
	cout << s.isMatch("aaa", "a.a") << endl;*/
	cout << s.isMatch("aaa", "ab*a*c*a") << endl;
	return 0;
}

