// lt25.cpp : Defines the entry point for the console application.
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

private:
	void print(ListNode *p_ln)
	{
		while (p_ln != nullptr) {
			cout << p_ln->val << " ";
			p_ln = p_ln->next;
		}
		cout << endl;
	}

public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		
		ListNode *p_0 = head;
		ListNode *p_k = head;
		ListNode *p_nh = head;		
		ListNode *p_prev_0 = nullptr;

		if ( (k <= 1) || (head == nullptr)) {
			return head;
		}

		while (p_0) {
			int i = 0;
			while (i < k) {
				if (p_k) {
					p_k = p_k->next;
				}
				else {
					return p_nh;
				}
				++i;
			}
			
			ListNode *p_ln = p_0;
			ListNode *p_prev = p_k;
			i = 0;
			while (i < k) {
				ListNode *p_temp = p_ln->next;
				p_ln->next = p_prev;
				p_prev = p_ln;
				p_ln = p_temp;
				++i;
			}
			
			if (p_nh == head) {
				p_nh = p_prev;
			}

			if (p_prev_0)
				p_prev_0->next = p_prev;
			p_0->next = p_k;
			p_prev_0 = p_0;
			p_0 = p_k;
			//print(p_nh);
			//print(p_0);
		}

		return p_nh;
	}
};

int main()
{
	Solution s;

	ListNode *p_head = new ListNode(1);
	p_head->next = new ListNode(2);
	p_head->next->next = new ListNode(3);
	p_head->next->next->next = new ListNode(4);
	p_head->next->next->next->next = new ListNode(5);
	p_head->next->next->next->next->next = new ListNode(6);
	p_head->next->next->next->next->next->next = nullptr;

	ListNode *p_ln = s.reverseKGroup(p_head, 1);
	while (p_ln) {
		cout << p_ln->val << " ";
		p_ln = p_ln->next;
	}
	cout << endl;

    return 0;
}

