#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
  while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

class Solution {

private:
			
public:

		ListNode *getPreMiddle(ListNode *head)
		{
			ListNode *slow, *fast, *middle;
			slow = fast = middle = head;

			while ( (fast->next != nullptr) && (fast->next->next != nullptr) ) {
				slow = slow->next;
				fast = fast->next->next;
			}

			return slow;
		}
	
		ListNode *reverse(ListNode *head)
		{
			if (!head) return head;

			ListNode *prev = nullptr;

			while (head) {
				ListNode *temp = head->next;
				head->next = prev;
				prev = head;
				head = temp;
			}

			return prev;
		}

    void reorderList(ListNode* head) {

			if (head == nullptr) return;

			ListNode *preMid = getPreMiddle(head);	
			
			ListNode *mid = reverse(preMid->next);

			while (mid != nullptr) {
				ListNode *temp = head->next;
			  head->next = mid;
				ListNode *temp1 = mid->next;
				mid->next = temp;
				head = temp;
				mid = temp1;
			}
			head->next = mid;
    }

};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
//head->next->next = nullptr;
	head->next->next = new ListNode(3);
 	head->next->next->next = nullptr;
	/*
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = nullptr;
	*/
	Solution s;
	s.reorderList(head);
	print(head);	 
	return 0;
}

