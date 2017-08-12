#include <iostream>

using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};

class Solution {
  public:

    void connectComplex(TreeLinkNode *root)
    {
      if (!root) return;
        
      TreeLinkNode *p_node = root;

      while (p_node->next) {
        if (p_node->right) {
          p_node->right->next = p_node->next->left;
        }
        p_node = p_node->next;
      }   

      connectComplex(root->left);
    }   

    void connectSimple(TreeLinkNode *root)
    {   
      if (root) {
        if (root->left) {
          root->left->next = root->right;
        }
        connectSimple(root->left);
        connectSimple(root->right);
      }   
    }   

    void connect(TreeLinkNode *root) 
    {         
      connectSimple(root);
      connectComplex(root);
    }   
};

int main()
{

	return 0;
}
