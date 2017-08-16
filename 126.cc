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

		void populateSequences(const std::string &beginWord,
                           int minCost,
													 unordered_map<string, vector<string> > &tx,
													 unordered_map<string, int> &minTx,
													 vector<string> tempVec,
													 vector<vector<string>> &result)
		{
			if (minCost == 0) {
				result.emplace_back(tempVec);
				return;
			}

			for (const auto &word : tx[beginWord]) {
				if ( minTx[word] == minCost ) {
					tempVec.emplace_back(word);
					populateSequences(word, minCost - 1, tx, minTx, tempVec, result);
					tempVec.pop_back();
				}
			}
		}

public:
    vector<vector<string>> 
		findLadders(string beginWord, string endWord, vector<string>& wordList) 
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

			vector<string> tempVec{beginWord};
			populateSequences(beginWord, minCost, tx, minTx, tempVec, result);
	
			return result;
    }
};

int main()
{
	Solution s;
	/*
	vector<string> wordList{"hot","dot","dog","lot","log","cog"};
	auto vecStrVec = s.findLadders("hit", "cog", wordList);
	*/
	vector<string> wordList{"a","b","c"};
	auto vecStrVec = s.findLadders("a", "c", wordList);
	for (auto vs : vecStrVec) {
		for (auto s : vs) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
