#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
		{
    	vector<vector<int>> pSums;
			vector<int> path;
			pathSum(root, sum, 0, path, pSums);
			return pSums; 
    }

		bool isLeaf(TreeNode *root) { return !(root->left || root->right); }

		void pathSum(TreeNode *root, int sum, int curSum,
                 vector<int> &path,
								 vector<vector<int>> &pSums)
		{
			if (root == nullptr) return;
	
			path.emplace_back(root->val);
			
			if (isLeaf(root)) {
				if ((curSum + root->val) == sum)
					pSums.emplace_back(path);
			} else {
				pathSum(root->left, sum, curSum + root->val, path, pSums);	
				pathSum(root->right, sum, curSum + root->val, path, pSums);
			}
	
			path.pop_back();
		}
};

int main()
{
	return 0;
}
