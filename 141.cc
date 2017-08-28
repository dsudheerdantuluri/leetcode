#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
      bool hasCycle(ListNode *head) 
      {
        ListNode *slow, *fast;
        slow = fast = head;

        while (fast != nullptr) {
          slow = slow->next;
          fast = fast->next;
          if (fast) {
              fast = fast->next;
              if (slow == fast)  return true;
          }
        }

        return false;
      }
};

int main()
{

  return 0;
}
