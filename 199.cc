#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

			vector<int> result;

			if (root == nullptr) return result;

			queue<TreeNode *> q;

			q.push(root);
			q.push(nullptr);

			while (!q.empty()) {
		
				TreeNode *right = q.front();

				if (right == nullptr) break;

				result.push_back(right->val);

				while (q.front() != nullptr) {

					TreeNode *t = q.front();

					q.pop();

					if (t->right) q.push(t->right);

					if (t->left) q.push(t->left);

				}

				q.pop(); q.push(nullptr);
			}

			return result;		        
    }
};

int main()
{

	return 0;
}
