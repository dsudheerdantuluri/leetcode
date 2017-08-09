#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
	public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
		{ 
    	return sortedArrayToBST(nums, 0, nums.size()-1); 
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right)
		{
			if (left > right) return nullptr;

			auto mid = left + (right-left)/2;

			TreeNode *root = new TreeNode(nums[mid]);

   		root->left = sortedArrayToBST(nums, left, mid-1);

			root->right = sortedArrayToBST(nums, mid+1, right);

			return root; 
    }
		
};

int main()
{
	return 0;
}
