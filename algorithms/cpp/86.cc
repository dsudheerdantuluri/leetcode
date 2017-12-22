#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
       if (head == nullptr) return head;

       ListNode *p_node = head;
 			 ListNode *tail = head;
       ListNode *nh = nullptr;
       ListNode *prev = nullptr;
       unsigned numNodes = 1;
       while ( tail->next != nullptr ) {
        ++numNodes;
				tail = tail->next;
			 }

       for (unsigned i=0; i<numNodes; ++i) {
         if ( p_node->val >= x ) {
         	ListNode *temp = p_node->next;
          p_node->next = nullptr;
          if (tail != p_node) {
						tail->next = p_node;
						tail = tail->next;
					}
          if (prev) prev->next = temp;
          p_node = temp;
         } else {
           prev = p_node;
           if (!nh) nh = p_node;
           p_node = p_node->next;
         }
			 } 
      
       if(!nh) nh = head;
       return nh; 
    }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = nullptr; 
 
  Solution s;
  ListNode *p_node = s.partition(head, 0);
  while(p_node) {
  	cout << p_node->val << " ";
    p_node = p_node->next;
	}

  cout << endl;

	return 0;
}
