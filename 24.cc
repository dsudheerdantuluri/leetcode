// lt24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

		if ( (head == nullptr) || (head->next == nullptr) ) {
			return head;
		}

		ListNode *p_l = head;
		ListNode *p_ret = head->next;
		ListNode *p_prev = nullptr;

		while ( (p_l != nullptr) && (p_l->next != nullptr) ) {			
			ListNode *temp = p_l->next->next;
			p_l->next->next = p_l;
			if (p_prev) {
				p_prev->next = p_l->next;
			}
			p_l->next = temp;			
			p_prev = p_l;
			p_l = p_l->next;
		}

		return p_ret;
	}
};


int main()
{
	ListNode *p_l = new ListNode(1);
	p_l->next = new ListNode(2);
	p_l->next->next = new ListNode(3);
	p_l->next->next->next = new ListNode(4);
	p_l->next->next->next->next = nullptr;

	Solution s;
	auto p_head = s.swapPairs(p_l);
	while (p_head) {
		cout << p_head->val << " ";
		p_head = p_head->next;
	}
	cout << endl;

    return 0;
}

