// leetcode66PlusOne.cpp : 定义控制台应用程序的入口点。
//
//Given a non - negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.
#include "stdafx.h"
#include "malloc.h"
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int lastPos = digitsSize - 1;
	*returnSize = digitsSize + 1;
	/*if (digits[lastPos] < 9)
	{
	digits[lastPos]++;
	return digits;
	}
	else
	{*/
	int* result = (int*)malloc((*returnSize)*sizeof(int));
	int i = lastPos;
	while (digits[i] == 9 && i >= 0)
	{
		*(result + i + 1) = 0;
		i--;
	}
	if (i == -1)
	{
		*(result + i + 1) = 1;
		return result;
	}
	else{
		(*returnSize)--;
		*(result + i + 1) = digits[i] + 1;
		for (int j = 1; j <= i; j++)
		{
			*(result + j) = digits[j - 1];
		}
		return (result + 1);
	}
	/*}*/
}

int _tmain(int argc, _TCHAR* argv[])
{
	int test[2] = { 9, 8 };
	return 0;
}

