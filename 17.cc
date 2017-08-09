// 17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {

private:
	void letterCombinationsRec(const std::string &digits, map<char, string> &numToChars, vector<int> indices, vector<string> &lcVec, unsigned int fi)
	{
		string s("");
		if (fi == digits.size()) {
			for (auto i = 0; i < digits.size(); ++i) {
				s += numToChars[digits[i]][indices[i]];
			}
			lcVec.push_back(s);
			//cout << "s:" << s.c_str() << endl;
			return;
		}
		
		
		for (auto k = 0; k < numToChars[digits[fi]].size(); ++k) {
			indices[fi] = k;
			letterCombinationsRec(digits, numToChars, indices, lcVec, fi+1);
		}
		
	}

public:
	vector<string> letterCombinations(string digits) {

		map<char, string> numToChars{
			make_pair<char, string>('2', "abc"),
			make_pair<char, string>('3', "def"),
			make_pair<char, string>('4', "ghi"),
			make_pair<char, string>('5', "jkl"),
			make_pair<char, string>('6', "mno"),
			make_pair<char, string>('7', "pqrs"),
			make_pair<char, string>('8', "tuv"),
			make_pair<char, string>('9', "wxyz")
		};

	
		vector<string> lcVec;
		if (digits == "") {
			lcVec.push_back("");
			return lcVec;
		}

		vector<int> indices(digits.size(), 0);
		letterCombinationsRec(digits, numToChars, indices, lcVec, 0);
		
		return lcVec;
	}
};

int main()
{
	Solution s;
	auto vec = s.letterCombinations("23");
	for (auto str : vec) {
		cout << str.c_str() << " ";
	}
	cout << endl;
    return 0;
}

