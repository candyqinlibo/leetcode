// leetcode15MinStack.cpp : 定义控制台应用程序的入口点。
//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
#include "stdafx.h"
#include "malloc.h"
typedef struct MinStack{
	int *data;
	int *top;
	int size;
	int min;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
	stack->min = 0;
	stack->size = 0;
	stack->data = (int*)malloc(maxSize*sizeof(int));
	stack->top = stack->data;
}

void minStackPush(MinStack *stack, int element) {
	stack->size++;
	*(stack->top) = element;
	stack->top++;
	if (stack->size == 1)
	{
		stack->min = element;
	}
	else
	{
		if (stack->min > element)
		{
			stack->min = element;
		}
	}
	
}

void minStackPop(MinStack *stack) {
	if (stack->size <= 0) return;
	stack->top--;
	int toptemp = *(stack->top);
	stack->size--;
	if (stack->min == toptemp)
	{
		stack->min = stack->data[0];
		for (int i = 0; i < stack->size; i++)
		{
			if (stack->data[i] < stack->min)
			{
				stack->min = stack->data[i];
			}
		}
	}
}

int minStackTop(MinStack *stack) {
	stack->top--;
	int temp = *(stack->top);
	stack->top++;
	return temp;
}

int minStackGetMin(MinStack *stack) {
	return stack->min;
}

void minStackDestroy(MinStack *stack) {
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->top = NULL;
	stack->min = 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

