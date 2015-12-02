// leetcode203RemoveLinkedListElements.cpp : 定义控制台应用程序的入口点。
//
//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//Return: 1 --> 2 --> 3 --> 4 --> 5
#include "stdafx.h"
#include "limits.h"
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) return NULL;
	struct ListNode* temp;
	temp->val = INT_MAX;
	temp->next = head;
	struct ListNode* first = temp;
	struct ListNode* last = temp->next;
	while (last)
	{
		if (last->val == val)
		{
			first->next = last->next;
			last = last->next;
		}
		else
		{
			first = last;
			last = last->next;
		}
	}
	return temp->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

