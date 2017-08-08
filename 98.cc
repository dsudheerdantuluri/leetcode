#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
	private:
		void inorder(TreeNode *root, vector<int> &inorder_values)
		{
			if (root == nullptr) return;

			inorder(root->left, inorder_values);
			inorder_values.push_back(root->val);
			inorder(root->right, inorder_values);	
		}

	public:
		bool isValid(TreeNode *root)
		{
			if (!root) return true;

			vector<int> inorder_values;
			inorder(root, inorder_values);	

			for (int i=1; i < inorder_values.size(); ++i) {
				if ( inorder_values[i] <= inorder_values[i-1] ) {
					return false;
				}
			}

			return true;
		}	
};

int main()
{

	return 0;
}
