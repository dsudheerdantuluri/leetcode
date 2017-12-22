// 14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {

private:
	string longestCommonPrefix(const string &str1, const string &str2)
	{
		//cout << str1.c_str() << " " << str2.c_str() << endl;
		const string &sh = str1.length() <= str2.length() ? str1 : str2;
		const string &lg = str1.length() > str2.length() ? str1 : str2;		
		auto mbp = std::mismatch(sh.begin(), sh.end(), lg.begin());
		return string(sh.begin(), mbp.first);
	}

public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		string lcp("");

		if (strs.size() == 0u) {
			return lcp;
		} else if (strs.size() == 1) {
			return strs[0u];
		} else {
			lcp = longestCommonPrefix(strs[0], strs[1]);
			for (auto i = 2u; i < strs.size(); ++i) {
				lcp = longestCommonPrefix(lcp, strs[i]);
			}
		}

		return lcp;
	}
};

int main()
{
	Solution s;
	vector<string> vs({ "sudheer", "sudhee", "sud", "sudh" });
	cout << s.longestCommonPrefix(vs).c_str() << endl;
    return 0;
}

