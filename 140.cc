#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {

    unordered_map<string, vector<string>> cache;

    vector<string> wordBreak(string s, 
                             unordered_set<string>& wordDict)
    {
      if (cache.count(s)) return cache[s];
      vector<string> result;

      if (wordDict.count(s)) {
        result.emplace_back(s);
      }

      for (int i = 1; i < s.length(); ++i) {
        string temp(s.substr(i));
        if (wordDict.count(temp)) {
          string beg(s.substr(0,i));
          vector<string> prevResult=wordBreak(beg,wordDict);
          for (auto entry:prevResult) {
           string word = entry + " " + temp;
           result.emplace_back(word);
          }
        }
      }

      cache[s] = result;
      return result;
    }
  public:

    vector<string> wordBreak(string s, 
                             vector<string>& wordDict)
    {
      unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
      
      return wordBreak(s, wordDictSet);
    }
};

int main()
{
  Solution s;
  vector<string> wordDict{"leet", "code"};
  //cout << s.wordBreak("leetcode", wordDict) << endl;
  
  for (auto &str : s.wordBreak("leetcode", wordDict)) {
      cout << str << ";";
  }
  cout << endl;
}

