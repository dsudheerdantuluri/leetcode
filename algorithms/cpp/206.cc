#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	ListNode *prev = nullptr;

			while ( head != nullptr ) {
				ListNode *temp = head->next;
				head->next = prev;
				prev = head;
				head = temp;
			}

			return prev; 
    }
};

int main()
{
	return 0;
}
