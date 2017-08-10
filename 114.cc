#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
	public:
		TreeNode *getRightMostNode(TreeNode *root)
		{
			while (root && root->right) root = root->right;
			return root;
		}

		void flatten(TreeNode* root) 
		{
			while(root) {
				TreeNode *temp1 = root->right;
				TreeNode *temp2 = getRightMostNode(root->left);
				if (root->left) {
					root->right = root->left;
					temp2->right = temp1;
				}
				root->left = nullptr;
				root = root->right;
			}		
		}
};

int main()
{


}
