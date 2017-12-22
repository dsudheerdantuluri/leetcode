#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void rinorder(TreeNode *root, TreeNode *&prev, TreeNode *&n)
    {   
      if (root == nullptr) return;

      rinorder(root->right, prev, n); 
      if (prev && (prev->val <= root->val) && (!n)) n = prev;
      prev = root;
      rinorder(root->left, prev, n); 
    }   
    
    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&n)
    {   
      if (root == nullptr) return;

      inorder(root->left, prev, n); 
      if (prev && (prev->val >= root->val) && (!n)) n = prev;
      prev = root;
      inorder(root->right, prev, n); 
    }   

    void recoverTree(TreeNode* root) 
    {   
      if (!root) return;

      TreeNode *n1 = nullptr;
      TreeNode *n2 = nullptr;

      TreeNode *p1 = nullptr;
      TreeNode *p2 = nullptr;
  
      inorder(root, p1, n1);      
      rinorder(root, p2, n2);

      if (n1 && n2) swap(n1->val, n2->val);
    }
};


int main()
{
	TreeNode *r = new TreeNode(1);
	r->right = new TreeNode(1);

	Solution s;
	s.recoverTree(r);
	return 0;
}
