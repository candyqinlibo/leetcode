// leetcode2.cpp : 定义控制台应用程序的入口点。
//You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8
//

#include "stdafx.h"
#include "malloc.h"
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listNode;
listNode* makeNewNode();

struct  ListNode* addTwoNumbers(struct ListNode* l1,struct ListNode* l2)
{
	listNode* t1 = l1;
	listNode* t2 = l2;
	listNode* result = makeNewNode();
	listNode* p = 0;
	int c = 0;
	while (t1 != NULL || t2 != NULL || c != 0) 
	{
		if (p == 0) {
			p = result;
		}
		else {
			p->next = (listNode*)malloc(sizeof(listNode));
			p->next->val = 0;
			p = p->next;
		}
		int a = t1 != NULL ? t1->val : NULL;
		int b = t2 != NULL ? t2->val : NULL;
		int s = (a + b + c) % 10;
		c = (a + b + c) / 10;
		p->val = s;
		p->next = 0;
		t1 = t1->next == NULL ? NULL : t1->next;
		t2 = t2->next == NULL ? NULL : t2->next;
	}
	return result;
};

//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* p1 = l1;
//	struct ListNode* p2 = l2;
//	struct ListNode* ans = (struct ListNode*)malloc(sizeof(struct ListNode));
//	ans->val = 0;
//	struct ListNode* p = 0;
//	int c = 0;
//	while (p1 != 0 || p2 != 0 || c != 0) {
//		if (p == 0) {
//			p = ans;
//		}
//		else {
//			p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//			p->next->val = 0;
//			p = p->next;
//		}
//		int a = p1 != 0 ? p1->val : 0;
//		int b = p2 != 0 ? p2->val : 0;
//		int s = (a + b + c) % 10;
//		c = (a + b + c) / 10;
//		p->val = s;
//		p->next = 0;
//		p1 = p1 == 0 ? 0 : p1->next;
//		p2 = p2 == 0 ? 0 : p2->next;
//	}
//	return ans;
//}

listNode* makeNewNode()
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->next = 0;
	node->val = 0;
	return node;
}

listNode* makeNewNode(int val, listNode *next)
{
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->next = next;
	node->val = val;
	return node;
}

int main(void)
{
	listNode* l13 = makeNewNode(3, NULL);
	listNode* l12 = makeNewNode(4, l13);
	listNode* l1 = makeNewNode(2, l12);
	listNode* l23 = makeNewNode(4, NULL);
	listNode* l22 = makeNewNode(6, l23);
	listNode* l2 = makeNewNode(5, l22);
	listNode* output = addTwoNumbers(l1, l2);
	listNode* p = output;
	while (p->next != 0)
	{
		printf("%d->", p->val);
		p = p->next;
	}
	printf("%d\n",p->val);
	while (output->next != 0)
	{
		p = output;
		output = output->next;
		free(p);
	}
	return 0;
}