// lt23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

template<typename T> void print_queue(T& q) {
	while (!q.empty()) {
		std::cout << q.top()->val << " ";
		q.pop();
	}
	std::cout << '\n';
}


class Solution {

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {		
		
		auto f = [](ListNode *p_l1, ListNode *p_l2) { return (p_l1->val > p_l2->val); };
		std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(f)> q(f);

		for (auto l : lists) {
			if (l) {
				q.emplace(l);
			}
		}

		//print_queue(q);
		
		ListNode *p_ml = nullptr;

		if (!q.size()) {
			return p_ml;
		}

		p_ml = q.top();

		ListNode *p_prev = nullptr;
		while (!q.empty()) {
			ListNode *p_l = q.top();
			if (p_prev) {
				p_prev->next = p_l;
			}
			q.pop();
			p_prev = p_l;
			p_l = p_l->next;
			if (p_l) {
				q.emplace(p_l);
			}
		}

		return p_ml;
	}
};

int main()
{
	Solution s;
	
	ListNode *p_l1 = new ListNode(1); p_l1->next = nullptr;
	ListNode *p_l2 = new ListNode(2); p_l2->next = nullptr;
	ListNode *p_l3 = new ListNode(3); p_l3->next = nullptr;
	ListNode *p_l4 = new ListNode(4); p_l4->next = nullptr;
	ListNode *p_l5 = new ListNode(5); p_l5->next = nullptr;

	vector<ListNode *> vln({ p_l1, p_l2, p_l3, p_l4, p_l5 });

	auto p_ml = s.mergeKLists(vln);

	while (p_ml) {
		cout << p_ml->val << " ";
		p_ml = p_ml->next;
	}
	cout << endl;

    return 0;
}

