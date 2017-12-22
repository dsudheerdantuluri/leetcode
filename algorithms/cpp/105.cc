#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
		{
			if ( (preorder.size() == 0) || (inorder.size() == 0) ) return nullptr;

			return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
		TreeNode* buildTree(vector<int>& preorder, int pb, int pe, vector<int>& inorder, int ib, int ie)
		{
			if ( pe < pb ) return nullptr;

			if ( pe == pb ) return new TreeNode(preorder[pb]);

			int rootVal = preorder[pb];

			TreeNode *root = new TreeNode(rootVal);

			auto it = find(inorder.begin() + ib, inorder.begin() + ie + 1, rootVal);

			auto numLT = (it - inorder.begin()) - ib;

			auto numRT = (inorder.end() - it) - 1;

			root->left = buildTree(preorder, pb+1, pb+numLT, inorder, ib, ib+numLT-1); 
			
			root->right = buildTree(preorder, pb+numLT+1, pe, inorder, ib+numLT+1, ie);

			return root; 
		} 
};

int main()
{

	return 0;
}
