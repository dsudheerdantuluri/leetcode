#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
private:
		bool canTransform(const string &str1, const string &str2)
		{
			if (str1.length() != str2.length()) return false;
			
			int i = 0, diff = 0;
			while ( i < str1.length()) {
				if (str1[i] != str2[i]) ++diff;
				++i;
			}

			return (diff == 1);
		}

		void populateTransforms(const string &beginWord, 
                            vector<string>& wordList,
														unordered_map<string, vector<string>> &tx)
		{
			for ( int i = 0; i < wordList.size(); ++i ) {
				for ( int j = i+1; j < wordList.size(); ++j ) {
					const auto &word1 = wordList[i];
					const auto &word2 = wordList[j];
					if (canTransform(word1, word2)) {
						tx[word1].emplace_back(word2);
						tx[word2].emplace_back(word1);
					}
				}
			}

			if (tx.find(beginWord) == tx.end()) {
				for (const auto &word : wordList) {
					if (canTransform(beginWord, word)) {
						tx[beginWord].emplace_back(word);
					}
				}
			}
		}

public:
		int ladderLength(string beginWord, string endWord, vector<string>& wordList)
		{
			vector<vector<string>> result;

			unordered_map<string, int> minTx;

			unordered_map<string, vector<string> > tx;

			populateTransforms(beginWord, wordList, tx);
       
			for (const auto &word : wordList) {
				minTx[word] = numeric_limits<int>::max();
			}
		
			minTx[endWord] = 1;

			bool changes = true;

			while (changes) {
				changes = false;
				for (const auto &word : wordList) {
					for (const auto &tw : tx[word]) {
						if (minTx[tw] != numeric_limits<int>::max()) {
							if (minTx[word] > (minTx[tw] + 1)) {
								minTx[word] = minTx[tw] + 1;
								changes = true;
							}
						}
					}
				}
			}
		
			int minCost = numeric_limits<int>::max(); 

			for (const auto &word : tx[beginWord])
				minCost = min(minCost, minTx[word]);

			return (minCost == numeric_limits<int>::max()) ? 0 : (minCost+1);
    }
};

int main()
{
	Solution s;
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	cout << s.ladderLength("hit", "cog", wordList) << endl;
	return 0;
}
