#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    ListNode* reverse(ListNode* p_node, int k) 
		{
			ListNode *prev = nullptr; 
			ListNode *curr = p_node;
			ListNode *p_temp = nullptr;

			for (int i = 1; i <= k; ++i) {
				p_temp = curr->next;
				curr->next = prev;
				prev = curr;
				curr = p_temp;
			}

			if (p_temp) p_node->next = p_temp;

			return prev;
		}

    ListNode* reverseBetween(ListNode* head, int m, int n) 
		{
			if (head == nullptr) return head;
		
			ListNode *p_node = head;
			ListNode *prev = nullptr;
			for (int i = 1; i < m ; ++i ) {
				prev = p_node;
				p_node = p_node->next;
			}

      ListNode *tail = reverse(p_node, n-m+1);
			if (prev) prev->next = tail; 

			return prev ? head : tail;
    }
};

void print(ListNode *head)
{
	while ( head != nullptr ) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = nullptr; 

	Solution s;
	head = s.reverseBetween(head, 2, 6);
  print(head);
	
	return 0;
}
