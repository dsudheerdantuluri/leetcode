#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
		{
			vector<int> result;

			stack<TreeNode *> s;	

			while (1) {

				while (root) {
					result.emplace_back(root->val);
					s.push(root);
					root = root->left;
				}
	
				if (s.empty()) break;

				root = s.top(); s.pop();

				root = root->right;	
			
			}

			return result;        
    }
};


int main()
{
	return 0;
}

