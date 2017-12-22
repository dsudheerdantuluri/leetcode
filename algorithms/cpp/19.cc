// lt19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

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


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		if ((head == nullptr) || (n <= 0)) {
			return head;
		}

		ListNode *p_node = head;

		for (auto i = 1; i <= n; ++i) {
			if (!p_node) {
				return head;
			}
			p_node = p_node->next;
		}

		ListNode *p_nthNodeFromEnd = head;
		ListNode *p_prev = nullptr;

		while (p_node != nullptr) {
			p_node = p_node->next;
			p_prev = p_nthNodeFromEnd;
			p_nthNodeFromEnd = p_nthNodeFromEnd->next;
		}

		if (p_prev != nullptr) {
			p_prev->next = p_nthNodeFromEnd->next;
			delete p_nthNodeFromEnd;
		}
		else {
			ListNode *temp = head;
			head = head->next;
			delete temp;
			return head;
		}

		return head;
	}
};
int main()
{

    return 0;
}

