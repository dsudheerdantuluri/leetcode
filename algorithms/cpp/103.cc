#include <vector>
#include <queue>
#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
		{
			vector<vector<int>> result;

			if (!root) return result;

			queue<TreeNode *> q;

			q.push(root);
			q.push(nullptr);

			bool rev = false;

			while (!q.empty()) {
				
				vector<int> v;

				TreeNode *p_node = q.front();q.pop();

				while (p_node) {
					v.push_back(p_node->val);
					if (p_node->left) q.push(p_node->left);					
					if (p_node->right) q.push(p_node->right);					
					p_node = q.front();q.pop();
				}

				if (rev) reverse(v.begin(), v.end());

				result.push_back(v);

				rev = !rev;

				if (!q.empty()) q.push(nullptr);	

			}

			return result;
    }
};

int main()
{
	return 0;
}
