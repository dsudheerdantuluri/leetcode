#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
    int maxPathSum(TreeNode* root) 
		{
			int maxVal = numeric_limits<int>::min();
			maxPathSum(root, maxVal);
			return maxVal;
    }

		int maxPathSum(TreeNode *root, int &maxVal)
		{
			if (root == nullptr) return 0;

			//cout << "root->val:" << root->val << endl;
			int leftVal = max(maxPathSum(root->left, maxVal), 0);
			int rightVal = max(maxPathSum(root->right, maxVal), 0);
			auto pathVal = max(leftVal, rightVal) + root->val;
      auto treeVal = leftVal + rightVal + root->val;
			//cout << "maxVal:" << maxVal << endl;
			//cout << "pathVal:" << pathVal << endl;
			maxVal = max(pathVal, maxVal);
			//cout << "treeVal:" << treeVal << endl;
			maxVal = max(treeVal, maxVal);
			//cout << "maxVal:" << maxVal << endl;
			return pathVal;
		}
};

int main()
{
	TreeNode *root = new TreeNode(-2);
	root->left = new TreeNode(1);
	Solution s;
	cout << s.maxPathSum(root) << endl;
	return 0;
}
