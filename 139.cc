#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

  public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
      vector<bool> result(s.length(), false);

      for (int i=0; i < s.length(); ++i) {
          for (int j=0; j < i; ++j) {
              auto it = find(wordDict.begin(), wordDict.end(), s.substr(j+1, i-j));
              result[i] = result[j] && (it != wordDict.end());
              if (result[i]) break;
          }
          auto it = find(wordDict.begin(), wordDict.end(), s.substr(0, i+1));
          result[i] = result[i] || (it != wordDict.end());
      }

      return result[s.length()-1];
    }
};

int main()
{
  Solution s;
  vector<string> wordDict{"leet", "code"};
  cout << s.wordBreak("leetcode", wordDict) << endl;
}

