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
    bool hasPathSum(TreeNode* root, int sum) 
    { 
      if (root == nullptr) return false;
      return hasPathSum(root, sum, 0); 
    }   

    bool hasPathSum(TreeNode* root, int sum, int curSum)
    {   
      if (root == nullptr) return false;

      if ((root->left == nullptr) && (root->right == nullptr)) {
        return (root->val + curSum == sum);
      }

      return hasPathSum(root->left, sum, curSum + root->val) ||
             hasPathSum(root->right, sum, curSum + root->val);
    }
};


int main()
{

	return 0;
}
