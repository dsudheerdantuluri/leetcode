#include <iostream>
#include <unordered_map>

using namespace std;

class Trie {

		typedef struct TrieNode {
			bool word;
			unordered_map<char, TrieNode *> hash;
			TrieNode() : word(false) {}
		} TrieNode;

    TrieNode *mp_root;

public:
    /** Initialize your data structure here. */
    Trie() {
			mp_root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
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
				if ( i == word.length() - 1 ) p_node->word = true;
			}
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
			TrieNode *p_node = mp_root;
			for (auto c: word) {
				auto it = p_node->hash.find(c);
				if ( it != p_node->hash.end() ) {
					p_node = it->second;
				} else {
					return false;
				}
			}
      return p_node->word;  
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
			TrieNode *p_node = mp_root;
			for (auto c: prefix) {
				auto it = p_node->hash.find(c);
				if ( it != p_node->hash.end() ) {
					p_node = it->second;
				} else {
					return false;
				}
			}
      return true;  
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main()
{
	return 0;
}
