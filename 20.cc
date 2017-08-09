// 20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stack>

using namespace std;

class Solution {

	private:
	
	bool isMatch(char a, char b) {
		return (
			(a == '(' && b == ')') ||
			(a == '{' && b == '}') ||
			(a == '[' && b == ']')
			);
	}

	public:
	
	bool isValid(string s) {
	
		stack<char> st;
		
		for (auto c : s) {
			if (!st.empty() && (isMatch(st.top(), c))) {
				st.pop();
			} else {
				st.emplace(c);
			}
		}

		return st.empty();
	}
};

int main()
{
	Solution s;
	cout << s.isValid("()") << endl;
	cout << s.isValid("()[]{}") << endl;
	cout << s.isValid("(]") << endl;
	cout << s.isValid("([)]") << endl;
    return 0; 
}

