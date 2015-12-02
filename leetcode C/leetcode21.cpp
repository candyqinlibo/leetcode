// leetcode21.cpp : 定义控制台应用程序的入口点。
//
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
#include "stdafx.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head = NULL;
	struct ListNode* current = NULL;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	if (l1->val < l2->val)
	{
		head = l1; 
		l1 = l1->next;
	}
	else 
	{
		head = l2; 
		l2 = l2->next;
	}
	current = head;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			current->next = l1;
			current = current->next;
			l1 = l1->next;
		}
		else
		{
			current->next = l2;
			current = current->next;
			l2 = l2->next;
		}
	}
	if (l1 == NULL)
	{
		current->next = l2;
	}
	if (l2 == NULL)
	{
		current->next = l1;
	}	
	return head;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

