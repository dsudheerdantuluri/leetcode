#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
		{

			int count = 0; 

			ListNode *p_last = nullptr;
			for (ListNode *p_n = head; p_n != nullptr; p_n = p_n->next) {
				++count;
				p_last = p_n;
			}

			if (count <= k) {
				return head;
			}

			ListNode *p_prev = nullptr, *p_k = head;
			for (int i = 1; i <= count-k; ++i) {
				p_prev = p_k;
				p_k = p_k->next;
			}

			p_prev->next = nullptr;
			p_last->next = head;		
		
      return p_k; 
    }
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = nullptr; 
	//head->next->next->next->next->next->next = nullptr;

	ListNode *p_n = s.rotateRight(head, 2);
	while (p_n) {
		cout << p_n->val << " ";
		p_n = p_n->next;
	} 
	cout << endl;
 	
}
