#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
		int getLength(ListNode *head)
		{
			int count = 0;

			while (head) {
				++count;
				head = head->next;
			}

			return	count; 
		}
			
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
		{
			int lenA = getLength(headA);

			int lenB = getLength(headB);

			ListNode *&head = (lenA > lenB) ? headA : headB;

			int diff = abs(lenA - lenB);

			while (diff--) head = head->next;

			while ( (headA != nullptr) && (headB != nullptr) ) {

				if (headA == headB) return headA;

				headA = headA->next;
	
				headB = headB->next;

			}

			return nullptr;
    }
};

int main()
{
	return 0;
}
