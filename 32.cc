// lt32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) 
	{
		stack<int> pStack;

		if (s.length() == 1) {
			return 0;
		}

		for ( auto i = 0 ; i < s.length() ; ++i ) {
			if ( !pStack.empty() && (s[pStack.top()] == '(') && s[i] == ')' ) {
				pStack.pop();
			} else {
				pStack.emplace(i);
			}
		}

		if (pStack.empty()) {
			return s.length();
		}

		auto maxIndex = s.length() - 1;
		auto lsl = 0;
		while (!pStack.empty()) {
			lsl = max(lsl, (int) maxIndex - pStack.top());
			maxIndex = pStack.top() - 1;
			pStack.pop();
		}
		lsl = max(lsl, (int) maxIndex + 1);

		return lsl;
	}
};

int main()
{
	Solution s;
	cout << s.longestValidParentheses(")()())") << endl;
	cout << s.longestValidParentheses("(()") << endl;
	cout << s.longestValidParentheses(")(())((())") << endl;
	cout << s.longestValidParentheses(")(())((()))") << endl;
	cout << s.longestValidParentheses("()") << endl;	
	cout << s.longestValidParentheses("())") << endl;
    return 0;
}

