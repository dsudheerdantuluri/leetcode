#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
			unordered_map<char, int> h;
			for (auto c: t)
				h[c]++;

			int begin = 0, end = 0, mwl = numeric_limits<int>::max(), head = 0, count = t.length();
			while ( end < s.length() ) {
				if ( h.find(s[end]) != h.end() ) {
					if ( h[s[end]] > 0 ) count--;
					h[s[end]]--;
				}
				while (count == 0) {
					if ( (end-begin+1) < mwl ) mwl = end - (head=begin) + 1;
					if ( h.find(s[begin]) != h.end() ) {
						if ( h[s[begin]] == 0 ) count++;
						h[s[begin]]++;
					}
					begin++;
				}
				++end;
			} 		

			return mwl == numeric_limits<int>::max() ? "" : s.substr(head, mwl);	
    }
};

int main()
{
	Solution s;
  //"cabwefgewcwaefgcf"
  //"cae"
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
	cout << s.minWindow("cabwefgewcwaefgcf", "cae") << endl;
	return 0;
}
