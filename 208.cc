#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {

private:

		struct TrieNode {
			char c;
			bool w;
			vector<TrieNode *> children;
			TrieNode(char in_c, bool in_w) : c(in_c), w(in_w) {}; 
		};

		using TrieNode = struct TrieNode;

	  vector<TrieNode *> m_roots;

		TrieNode *getTrieNode(string word, vector<TrieNode *> &roots, bool create = false)
		{
			TrieNode *p_tn = nullptr;
			vector<TrieNode *> *p_nodes = &roots;
			for (int i = 0; i < word.length(); ++i ) {
				char key = word[i];
				auto it = find_if(p_nodes->begin(), p_nodes->end(), [key](TrieNode *t) { return key == t->c; });
				if ( it == p_nodes->end() ) {
					if (create) { 
						p_tn = new TrieNode(key, ((i+1) == word.length()));
					} else {
						return nullptr;		
					}
				} else {
					p_tn = *it;
					if (create) p_tn->w = p_tn->w || ((i+1) == word.length());
				}
				p_nodes->emplace_back(p_tn); 
				p_nodes = &p_tn->children;	
			}

			return p_tn;	
		}

public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
			getTrieNode(word, m_roots, true /*create*/);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
			TrieNode *p_tn = getTrieNode(word, m_roots);
			return p_tn && p_tn->w;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
			return getTrieNode(prefix, m_roots) != nullptr;
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
	Trie *obj = new Trie();
	/*
	obj->insert("abc");
	cout << obj->search("abc") << endl;
	cout << obj->search("ab") << endl;
	obj->insert("ab");
	cout << obj->search("ab") << endl;
	obj->insert("ab");
	cout << obj->search("ab") << endl;
	*/

	obj->insert("app");
	obj->insert("apple");
	obj->insert("beer");
	obj->insert("add");
	obj->insert("jam");
	obj->insert("rental");
	cout << obj->search("apps") << endl;
	cout << obj->search("app") << endl;
	cout << obj->search("ad") << endl;

	return 0;
}
