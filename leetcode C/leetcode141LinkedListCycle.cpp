// leetcode141LinkedListCycle.cpp : 定义控制台应用程序的入口点。
//
//Given a linked list, determine if it has a cycle in it.
#include "stdafx.h"
struct ListNode {
	int val;
	struct ListNode *next;	
};

bool hasCycle(struct ListNode *head) {
	if (head == NULL) return false;
	struct ListNode* first = head->next;
	struct ListNode* second = head;
	while (first && second)
	{
		if (first->val == second->val)
		{
			return true;
		}
		else{
			if (first->next)
			{
				first = first->next->next;
				second = second->next;
			}
			else return false;
		}
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

