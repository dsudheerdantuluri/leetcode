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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
		{
			if ( (postorder.size() == 0) || (inorder.size() == 0) ) return nullptr;

			return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
		
		TreeNode* buildTree(vector<int>& postorder, int pb, int pe, vector<int>& inorder, int ib, int ie)
		{
			if ( pe < pb ) return nullptr;

			if ( pe == pb ) return new TreeNode(postorder[pe]);

			int rootVal = postorder[pe];

			TreeNode *root = new TreeNode(rootVal);

			auto it = find(inorder.begin() + ib, inorder.begin() + ie + 1, rootVal);

			auto numLT = (it - inorder.begin()) - ib;

			auto numRT = (inorder.end() - it) - 1;

			root->left = buildTree(postorder, pb, pb+numLT-1, inorder, ib, ib+numLT-1); 
			
			root->right = buildTree(postorder, pb+numLT, pe-1, inorder, ib+numLT+1, ie);

			return root; 
		} 
};

int main()
{
	return 0;
}
