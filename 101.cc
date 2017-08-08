#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
		{
			if (root == nullptr) return true;

			return isSymmetricTrees(root->left, root->right);
    }
    bool isSymmetricTrees(TreeNode* t1, TreeNode *t2) 
		{
			return (!t1 && !t2) || 
             ( (t1 && t2) && (t1->val == t2->val) && 
               (isSymmetricTrees(t1->left, t2->right)) &&
							 (isSymmetricTrees(t1->right, t2->left)) );
		}
};
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root)
		{
			if (root == nullptr) return true;

			return isSymmetricTrees(root->left, root->right);
		}
    
		bool isSymmetricTrees(TreeNode* t1, TreeNode *t2) 
		{
	
			if (!t1 && !t2) return true;

      if (!t1 || !t2) return false;

			queue<TreeNode *> q1, q2;
			q1.push(t1);
			q2.push(t2);
		
			while (!q1.empty() && !q2.empty()) {

				TreeNode *p_node1 = q1.front();q1.pop();
				TreeNode *p_node2 = q2.front();q2.pop();

				if (p_node1 && p_node2) {
					if (p_node1->val != p_node2->val) return false;
				} else if (p_node1 || p_node2) {
					return false;
				}

				if (p_node1) {
					q1.push(p_node1->left);	
					q1.push(p_node1->right);
				}

				if (p_node2) {
					q2.push(p_node2->right);
					q2.push(p_node2->left);	
				}
	
			}

			if (q1.empty() && q2.empty()) return true;

			return false;

    }
};
 
int main()
{

	return 0;
}
