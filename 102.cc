#include <iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {   
      vector<vector<int>> result;
    
      if (!root)  return result;
    
      queue<TreeNode *> q;

      q.push(root);
      q.push(nullptr);

      while (!q.empty()) {

        TreeNode *p_node = q.front();
        vector<decltype(p_node->val)> v;

        while (p_node) {
          q.pop();
          v.emplace_back(p_node->val);
          if (p_node->left) q.emplace(p_node->left);
          if (p_node->right) q.emplace(p_node->right);
          p_node = q.front();
        }

        q.pop();  
        if (!q.empty()) q.push(nullptr);
        result.emplace_back(v);
      }   

      return result;
    
    }   
};

int main()
{
  TreeNode *root = new TreeNode(5);

	return 0;
}
