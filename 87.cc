#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    bool isScrambleImpl(const string &s1, const string &s2) 
    {
			 if (s1.length() != s2.length()) return false;

       if (!sameChars(s1, s2)) return false;

       auto n = s1.length();

       if (n <= 2) return true;

       for (unsigned d = 1; d < n; ++d) {
         
				if ( isScramble(s1.substr(0, d), s2.substr(0, d)) &&
             isScramble(s1.substr(d, n-d), s2.substr(d, n-d)) ) return true;

				if ( isScramble(s1.substr(0, d), s2.substr(n-d, d)) &&
             isScramble(s1.substr(d, n-d), s2.substr(0, n-d)) ) return true;

  		 }

       return false; 
    }

	public:

    bool sameChars(const string &s1, const string &s2)
		{
			unordered_map<char, unsigned> hash;
      bool result = true;

      for_each(s1.begin(), s1.end(), [&](char c) { hash[c]++; });
      for_each(s2.begin(), s2.end(), [&](char c) { hash[c]--; });
      for_each(hash.begin(), hash.end(), [&](const pair<char, unsigned> &p) { result = result && (p.second == 0); });

			return result;
		}

    bool isScramble(string s1, string s2) 
    {
    	return isScrambleImpl(s1, s2);
		} 
};

int main()
{
  Solution s;
  //cout << s.isScramble("great","rgeat") << endl;
  //cout << s.isScramble("great","rgtae") << endl;
  cout << s.isScramble("great","egrta") << endl;
	return 0;
}
