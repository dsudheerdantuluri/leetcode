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
    
    bool searchSR(string word) {
			return searchSR(mp_root, word, 0);
		}

    bool searchSR(TrieNode *mp_root, string &word, int index) {
			if (!mp_root) return false;
			if (index == word.length()) return true;
			char c = word[index];
			if ( c != '.' ) {
				auto it = mp_root->hash.find(c);
				if ( it == mp_root->hash.end() ) return false;
				else return searchSR(it->second, word, index+1);
			} else {
				bool ret = false;
				for ( const auto &entry : mp_root->hash ) {
					char c = entry.first;
					ret = ret || searchSR(entry.second, word, index+1);
				}
				return ret;
			}
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

class WordDictionary {
		Trie t;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
    	t.insert(word);  
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
			return t.searchSR(word);	
    }
};


int main()
{
	return 0;
}
