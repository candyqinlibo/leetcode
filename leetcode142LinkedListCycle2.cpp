// leetcode141LinkedListCycle2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL) return NULL;
	bool isCycle = false;
	struct ListNode* first = head;
	struct ListNode* second = head;
	while (first->next->next)
	{
		first = first->next->next;
		second = second->next;
		if (first->val == second->val)
		{
			isCycle = true;
			break;
		}
	}
	if (isCycle)
	{
		first = head;
		while (first->val != second->val)
		{
			first = first->next;
			second = second->next;
			if (first == head || second == head) return head;
		}
		return first;
	}
	else
	{
		return NULL;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

