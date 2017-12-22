#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
		ListNode *getCenter(ListNode *head)
		{
			ListNode *slow, *fast, *middle;
			slow = fast = head;

			while (fast != nullptr) {
				middle = slow;
				slow = slow->next;
				fast = fast->next;
				if (fast) {
					fast = fast->next;
				}	
			}

			return middle; 
		}

		ListNode *merge(ListNode *part1, ListNode *part2) 
		{
			if (!part1 && !part2) return nullptr;

			if (!part1) return part2;
			if (!part2) return part1;

			ListNode *head, *other;

			head = part1; other = part2;
			if (part2->val < part1->val) swap(head, other);
	
			ListNode *ret = head;
			ListNode *prev_head = nullptr;

			while ( (head != nullptr) && (other != nullptr)) {
				if (head->val <= other->val) {
					prev_head = head; 
					head = head->next;
				} else {
					ListNode *temp = other->next;
					prev_head->next = other;
					other->next = head;
					other = temp;
				}
			}

			if (other != nullptr) prev_head->next = other;

			return ret;
		}
    
		ListNode* sortList(ListNode* head) 
		{
			if ( (head == nullptr) || (head->next == nullptr) ) return head;

			//Partition into two halves
   		ListNode *preMid = getCenter(head);
			ListNode *part1 = head;
			ListNode *part2 = preMid->next;
			preMid->next = nullptr;
			
			//Sort each half
			part1 = sortList(part1);
			part2 = sortList(part2);

			//Merge
			ListNode *result = merge(part1, part2);

			return result;
    }
};

int main()
{
	return 0;
}
