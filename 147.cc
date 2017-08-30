#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
		{
			ListNode *sortedList = nullptr;
	
			while (head != nullptr) {

				ListNode *temp = head->next;

				head->next = nullptr;

				if (!sortedList) {
					sortedList = head;
				} else {
					insertSorted(sortedList, head);
				}

				head = temp;
			
			}

			return sortedList;
    }

		void insertSorted(ListNode *&sortedList, ListNode *node)
		{
			ListNode *temp = sortedList;

			ListNode *prev = nullptr;

			while (temp && (temp->val <= node->val)) {

				prev = temp;

				temp = temp->next;

			}
	
			if (prev) {
				node->next = prev->next;
				prev->next = node;
			} else {
				node->next = sortedList;
				sortedList = node;
			}
		}
};

int main()
{
	return 0;
}
