#include <iostream>
#include <algorithm>
#include <string>
#include <clocale>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) 
		{
			auto notAlnumFunc = [](unsigned char c) { return !isalnum(c); };
			transform(s.begin(), s.end(), s.begin(), ::tolower);
			s.erase(remove_if(s.begin(), s.end(), notAlnumFunc), s.end());
	    int beg = 0, end = s.size()-1;
			while (beg < end) { 
				if (s[beg++] != s[end--]) return false;
			}
			return true;	
    }
};

int main()
{
	Solution s;
	cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << s.isPalindrome("race a car") << endl; 
	cout << s.isPalindrome("") << endl; 
	return 0;
}
