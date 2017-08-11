#include <iostream>

using namespace std;

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	int val;
	TreeLinkNode(int v): val(v), left(NULL), right(NULL), next(NULL) {};
} ;


class Solution {
  public:

    void connectComplex(TreeLinkNode *root)
    {   
      if (!root) return;

      TreeLinkNode *prev  = nullptr;
      TreeLinkNode *curr = nullptr;

      TreeLinkNode *p_node = root;
      bool left = true;
    
      while (p_node) 
      {   
        if (left)
          curr = p_node->left; 
        else 
          curr = p_node->right;

        if (prev && curr && (prev != curr)) {
          prev->next = curr;
          prev = curr;   
        }        

        left = !left;

        if (left)
          p_node = p_node->next;
      }   

      p_node = root;
      while (p_node) {
        if (p_node->left) {
          connectComplex(p_node->left);
          break;
        } else if (p_node->right) {
          connectComplex(p_node->right);
          break;
        }
        p_node = p_node->next;
      }   
    }   

    void connectSimple(TreeLinkNode *root)
    {   
      if (root) {
        root->next = nullptr;
        connectSimple(root->left);
        connectSimple(root->right);
        if (root->left) {
          root->left->next = root->right;
        }
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
	TreeLinkNode *n1 = new TreeLinkNode(1);
	TreeLinkNode *n2 = new TreeLinkNode(2);
	TreeLinkNode *n3 = new TreeLinkNode(3);
	TreeLinkNode *n4 = new TreeLinkNode(4);
	TreeLinkNode *n5 = nullptr;
	TreeLinkNode *n6 = nullptr;
	TreeLinkNode *n7 = new TreeLinkNode(5);

  n1->left = n2;
  n1->right = n3;

	n2->left = n4;
  n2->right = n5;

	n3->left = n6;
	n3->right = n7;

  Solution s;
	s.connect(n1);
  
  print(n1);
 
	return 0;
}
