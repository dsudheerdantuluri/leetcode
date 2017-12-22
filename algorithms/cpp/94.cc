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
    vector<int> inorderTraversal(TreeNode* root) 
    {
    	vector<int> itnodes;
			TreeNode *t = root;
			if (t == nullptr) return itnodes;

			stack<TreeNode *> s;
			s.push(t);
			t = t->left;
			while (!s.empty()) {
				while (t != nullptr) {
					s.push(t);
					t = t->left;
				}
				t = s.top();s.pop();
				itnodes.emplace_back(t->val);
				t = t->right;
			}

			return itnodes;	
    }
};

int main()
{
	return 0;
}
