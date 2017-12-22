#include <iostream>
#include <unordered_map>

using namespace std;

class Solution 
{
  public:
    bool isIsomorphic(string s, string t) {
      if ( s.length() != t.length() ) return false;
      unordered_map<char, char> hash1;
      unordered_map<char, char> hash2;
      for ( int i = 0; i < s.length(); ++i ) { 
        auto it = hash1.find(s[i]);
        if ( it !=  hash1.end() ) 
          if ( it->second != t[i] ) return false;
        it = hash2.find(t[i]);
        if ( it != hash2.end() )
          if ( it->second != s[i] ) return false;
        hash1[s[i]] = t[i];
        hash2[t[i]] = s[i];  
      }   
      return true;
    }   
};

int main()
{
	return 0;
}
