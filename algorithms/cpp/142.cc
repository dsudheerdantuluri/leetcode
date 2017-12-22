#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

			ListNode *slow, *fast;

			slow = fast = head;

			bool hasLoop = false;

			while (fast != nullptr) {
				slow = slow->next;
				fast = fast->next;        
				if (fast) {
					fast = fast->next;
					if (slow == fast) {
						hasLoop = true;
						break;
					}
				}
			}

			if (!hasLoop) return nullptr;

			fast = head;

			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
	
			return slow;	
    }
};

int main()
{
	return 0;
}
