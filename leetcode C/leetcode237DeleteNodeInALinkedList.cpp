// leetcode237DeleteNodeInALinkedList.cpp : 定义控制台应用程序的入口点。
//
//Write a function to delete a node(except the tail) in a singly linked list, 
//given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
//the linked list should become 1 -> 2 -> 4 after calling your function.
#include "stdafx.h"
struct ListNode {
    int val;
    struct ListNode *next;	
};

void deleteNode(struct ListNode* node) {
	struct ListNode* next = node->next;
	node->val = next->val;
	node->next = next->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

