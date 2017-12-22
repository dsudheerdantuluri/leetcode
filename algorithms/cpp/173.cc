#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	
	stack<TreeNode *> s;        
	
	void leftPush(TreeNode *root)
	{
			while (root != nullptr) {
				s.push(root);
				root =root->left;
			}

	}	
public:
    BSTIterator(TreeNode *root) {
			leftPush(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
     return !s.empty();  
    }

    /** @return the next smallest number */
    int next() {
     TreeNode *root = s.top(); s.pop();
		 int val = root->val;
		 root = root->right;
		 leftPush(root);
		 return val;  
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
	return 0;
}
