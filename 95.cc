#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
		{
			vector<int> nodes(n, 0);
			for (int i=0; i<n ; ++i) {
				nodes[i] = i+1;
			}

			return generateTreesImpl(nodes);
		}

    vector<TreeNode*> generateTreesImpl(vector<int> &nodes) 
		{
			if (nodes.size() == 0) {
				vector<TreeNode *> v{nullptr};
				return v;
			}

			vector<TreeNode *> result;
      for (int i=0; i<nodes.size(); ++i) {
				auto rootVal = nodes[i];
				vector<int> leftVals, rightVals;
				copy_if(nodes.begin(), nodes.end(), back_inserter(leftVals), [rootVal](int val) { return val<rootVal; });
				copy_if(nodes.begin(), nodes.end(), back_inserter(rightVals), [rootVal](int val) { return val>rootVal; });
				auto lRoot = generateTreesImpl(leftVals);
				auto rRoot = generateTreesImpl(rightVals);
				for (auto l: lRoot) {
					for (auto r: rRoot) {
						TreeNode *root = new TreeNode(rootVal);
						root->left = l;
						root->right = r;
						result.emplace_back(root);
					}
				}
			}	
		
			return result;
		}
};

void print(TreeNode *t)
{
	if (t==nullptr) return;
	cout << t->val << " ";
	print(t->right);
	print(t->left);
}

int main()
{
	Solution s;
	vector<TreeNode *> v = s.generateTrees(3);
	for (auto t : v) {
		print(t);cout << endl;	
	}
	return 0;
}
