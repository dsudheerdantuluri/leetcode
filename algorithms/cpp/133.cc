#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

				if (!node) return nullptr;

				unordered_map<int, UndirectedGraphNode *> labelToNode;
			
				labelToNode[node->label] = new UndirectedGraphNode(node->label);
	
				cloneGraph(node, labelToNode[node->label], labelToNode);

  			return labelToNode[node->label];      
    }

		void cloneGraph(UndirectedGraphNode *node,
										UndirectedGraphNode *newNode, 
                    unordered_map<int, UndirectedGraphNode *> &labelToNode) 
		{
			if (!node || !newNode) return;

			for (auto p_c : node->neighbors) {
				
				auto it = labelToNode.find(p_c->label);

				UndirectedGraphNode *p_newNbour = nullptr;

				if (it == labelToNode.end())  { 
					p_newNbour = new UndirectedGraphNode(p_c->label);
					labelToNode[p_c->label] = p_newNbour; 
					cloneGraph(p_c, p_newNbour, labelToNode);
				} else {
          p_newNbour = it->second;	
				}
				
				newNode->neighbors.emplace_back(p_newNbour);
			}
		}
};

int main()
{
	return 0;
}
