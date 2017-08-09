#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isBalanced(TreeNode* root) 
		{
			pair<int, bool> db = getDepthAndBalance(root);
			return db.second;
		}

		pair<int, bool> getDepthAndBalance(TreeNode *root)
		{
			if (root == nullptr) return make_pair(0, true);

			auto ldb = getDepthAndBalance(root->left);
      auto rdb = getDepthAndBalance(root->right);
			auto balance = ldb.second && rdb.second && (abs(ldb.first-rdb.first) <= 1);
      auto depth = max(ldb.first, rdb.first)+1;

		  return make_pair(depth, balance);
		}

};

int main()
{
	return 0;
}
