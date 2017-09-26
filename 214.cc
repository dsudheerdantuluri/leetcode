#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
		void kmp(const string &str, vector<int> &table)
		{
			table[0] = 0;
			int j = 0, i = 1;
			while (i < table.size()) {
				if (str[i] == str[j]) {
					table[i++] = ++j;	
				} else if (j>0) {
				  j = table[j-1];	
				} else {
					table[i] = 0;
					++i;
				}
			}
		}
public:
    string shortestPalindrome(string s) {
			 if (s.length() == 0) return s;
			 string reverse_s(s);
			 reverse(reverse_s.begin(), reverse_s.end());
       string trickStr(s+"#"+reverse_s);
			 vector<int> table(trickStr.length(), 0);
			 kmp(trickStr, table);
			 string r(s.substr(table[trickStr.length() - 1]));
			 reverse(r.begin(), r.end());
			 r += s;
			 return r; 
    }
};

int main()
{

	return 0;
}
