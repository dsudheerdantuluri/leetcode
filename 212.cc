#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
		typedef struct TrieNode {
			bool word;
			string str;
			unordered_map<char, TrieNode *> hash;
			TrieNode() : word(false), str("") {}
		} TrieNode;

    TrieNode *mp_root;

    void insert(string word) {
			TrieNode *p_node = mp_root;
			for (size_t i = 0; i < word.length(); ++i) {
				auto it = p_node->hash.find(word[i]);
				if ( it != p_node->hash.end() ) {
					p_node = it->second;
				} else {
					TrieNode *p_new = new TrieNode();
					p_node->hash[word[i]] = p_new; 
					p_node = p_new;
				}
				if ( i == word.length() - 1 ) {
					p_node->word = true;
					p_node->str =	word; 	
				}
			}
    }

		void dfs(vector<vector<char>>& board, int i, int j, TrieNode *p_node, vector<string> &result) 
		{
			if (!p_node) return;

			char c = board[i][j];
			if ( (c == '#') || (p_node->hash.find(c) == p_node->hash.end()) ) return;

			if (p_node->word) {
				if (p_node->str != "") {
					result.push_back(p_node->str);
					p_node->str = "";
				} 
			}
			board[i][j] = '#';

			auto m = board.size();
			auto n = board[0].size();

			if (i-1 >= 0) dfs(board, i-1, j, p_node->hash[c], result);		
			if (j+1 < n)  dfs(board, i, j+1, p_node->hash[c], result);		
			if (i+1 < m)  dfs(board, i+1, j, p_node->hash[c], result);		
			if (j-1 >= 0) dfs(board, i, j-1, p_node->hash[c], result);	

			board[i][j] = c;	
		}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> result;
			mp_root = new TrieNode();
			for (const auto &w : words) {
				insert(w);
			}
      for (int i = 0;  i < board.size(); ++i) {
				for (int j = 0; j < board[0].size(); ++j) {
					dfs(board, i, j, mp_root, result);
				}
			}
			return result; 
    }
};

int main()
{
	return 0;
}
