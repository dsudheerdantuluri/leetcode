// lt22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	void generateParenthesis(vector<string> &vps, int n, int i, string s, int numOpen) 
	{	
		if (i == 2 * n) {
			vps.emplace_back(s);
			return;
		}

		auto numClose = s.length() - numOpen;
		if ( numOpen < n ) {
			generateParenthesis(vps, n, i + 1, s + "(", numOpen + 1);
		} 
		
		if (numClose < numOpen) {
			generateParenthesis(vps, n, i + 1, s + ")", numOpen);
		}
	}

public:
	vector<string> generateParenthesis(int n) {

		vector<string> vps;

		generateParenthesis(vps, n, 0, "", 0);

		return vps;
	}
};

int main()
{
	Solution s;
	auto vecStr = s.generateParenthesis(3);

	for (auto str : vecStr) {
		cout << str.c_str() << endl;
	}
    return 0;
}

