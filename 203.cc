#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
				while ( (head != nullptr) && (head->val == val) ) head = head->next;
				ListNode *ret = head;
				ListNode *prev = nullptr;
				while ( head != nullptr ) {
					if (head->val == val) {
							prev->next = head->next;
					} else {
							prev = head;
					}
					head = head->next;
				}
				return ret; 
    }
};

int main()
{
	return 0;
}
