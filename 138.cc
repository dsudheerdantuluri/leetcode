#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomListUsingMemory(RandomListNode *head) 
		{
			if (head == nullptr) return head;

			unordered_map<RandomListNode *, RandomListNode *> mapper;

			RandomListNode *p_node = head;

			while ( p_node != nullptr ) {
				mapper[p_node] = new RandomListNode(p_node->label);
				p_node = p_node->next;
			}
      
			mapper[nullptr] = nullptr;

			p_node = head;

			while (p_node != nullptr) {
				mapper[p_node]->next = mapper[p_node->next];
				mapper[p_node]->random = mapper[p_node->random];
				p_node = p_node->next;
			}

			return mapper[head]; 
    }

    RandomListNode *copyRandomListWithOutUsingMemory(RandomListNode *head) 
		{
			if (head == nullptr) return head;

			RandomListNode *p_node1 = head;

			RandomListNode *p_node2 = nullptr;

			RandomListNode *head_clone = nullptr;

			while (p_node1 != nullptr) {

				p_node2 = new RandomListNode(p_node1->label);

				if (!head_clone) head_clone = p_node2;

				p_node2->next = p_node1->random;

				p_node1->random = p_node2;

				p_node1 = p_node1->next;
		
			}

			p_node1 = head;

			p_node2 = head_clone;

		  while ( p_node1 != nullptr ) {

				RandomListNode *temp = p_node2->next;

				p_node2->random = p_node2->next ? p_node2->next->random : nullptr;

				p_node1 = p_node1->next;

				p_node2 = p_node1 ? p_node1->random : nullptr;

			}

			p_node1 = head;

			p_node2 = head_clone;

		  while ( p_node1 != nullptr ) {

				p_node1->random = p_node2->next;

				p_node2->next = p_node1->next ? p_node1->next->random : nullptr;

				p_node1 = p_node1->next;

				p_node2 = p_node2->next;       

			}

			return head_clone;
		}

		RandomListNode *copyRandomList(RandomListNode *head)
		{
			copyRandomListWithOutUsingMemory(head);
		} 
};

int main()
{
	return 0;
}
