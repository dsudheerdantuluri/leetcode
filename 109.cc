#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
		{
			unordered_map<int, ListNode *> arrList;
      ListNode *p_node = head;
      int pos = 0;
			
      while (p_node) {
				arrList[pos++] = p_node;
				p_node = p_node->next;
			}	

      return sortedListToBST(arrList, 0, arrList.size() - 1);  
    }

		TreeNode *sortedListToBST(unordered_map<int, ListNode *> &arrList, int left, int right)
		{
			if (left > right) return nullptr;

			auto mid = left + (right - left)/2;

      TreeNode *root = new TreeNode(arrList[mid]->val);

			root->left = sortedListToBST(arrList, left, mid-1);
			
			root->right = sortedListToBST(arrList, mid+1, right);

			return root;
		}
};

int main()
{
	return 0;
}

