#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    ListNode* deleteDuplicates(ListNode* head) 
		{
			if (head == nullptr) return head;

			ListNode *prev = nullptr;
			ListNode *curr = head;

			while (curr !=nullptr) {
			
				bool dup = false;

				while (curr->next && (curr->val == curr->next->val)) {
					ListNode *temp = curr->next;
					curr->next = temp->next;
					delete temp;
					dup = true;
				} 

				if (dup) {
					if (prev) {
						prev->next = curr->next;
						delete curr;
						curr = prev->next;
					} else {
					  head = curr->next;
						delete curr;
						curr=head;
					}	
				} else {
					prev = curr;
					curr = curr->next;
				}	
			}

    	return head;
    }
};

int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(1);
  /*
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next->next = nullptr;*/
  head->next->next = nullptr;

	Solution s;

	head = s.deleteDuplicates(head);

	while(head != nullptr) {
		cout << head->val << " ";
    head = head->next;
	}

	cout << endl;		
	
	return 0;
}
