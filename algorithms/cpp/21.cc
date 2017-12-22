// lt21.cpp : Defines the entry point for the console application.
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

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 class Solution {
 public:
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		 if (l1 == nullptr) {
			 return l2;
		 }

		 if (l2 == nullptr) {
			 return l1;
		 }

		 ListNode *p_nh = l1->val <= l2->val ? l1 : l2;

		 while ((l1 != nullptr) && (l2 != nullptr)) {

			 ListNode *p_prev_l1 = nullptr;
			 while ((l1 != nullptr) && (l1->val <= l2->val)) {
				 p_prev_l1 = l1;
				 l1 = l1->next;
			 }
			 if (p_prev_l1)
				 p_prev_l1->next = l2;

			 ListNode *p_prev_l2 = nullptr;
			 while ((l2 != nullptr) && (l1 != nullptr) && (l2->val < l1->val)) {
				 p_prev_l2 = l2;
				 l2 = l2->next;
			 }
			 if (p_prev_l2)
				 p_prev_l2->next = l1;
		 }

		 return p_nh;
	 }
 };

int main()
{
	Solution s;
	
	ListNode *p_l1 = new ListNode(1);
	p_l1->next = nullptr;

	ListNode *p_l2 = new ListNode(1);
	/*ListNode *p_l = p_l2;
	p_l2->next = new ListNode(2);
	p_l2 = p_l2->next;
	p_l2->next = new ListNode(4);
	p_l2 = p_l2->next;*/
	p_l2->next = nullptr;
	//p_l2 = p_l;

	//p_l1 = p_l2 = nullptr;
	ListNode *p_ml = s.mergeTwoLists(p_l1, p_l2);

	while (p_ml != nullptr) {		
		cout << p_ml->val << " ";
		p_ml = p_ml->next;
	}
	cout << endl;
    return 0;
}

