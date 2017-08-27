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
    RandomListNode *copyRandomList(RandomListNode *head) 
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
};

int main()
{

	return 0;
}
