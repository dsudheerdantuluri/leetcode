#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int sumNumbers(TreeNode* root) 
		{
			int sum = 0;
			sumNumbers(root, 0, sum);
			return sum;	
		}

		void sumNumbers(TreeNode *root, int curSum, int &sum)
		{
			if (root == nullptr) return;
			
			if ((root->left == nullptr) && (root->right == nullptr)) {
				curSum = curSum*10 + root->val;
				sum += curSum;
			}

			sumNumbers(root->left, curSum*10 + root->val, sum);
			sumNumbers(root->right, curSum*10 + root->val, sum);
		}
};

int main()
{
	return 0;
}
