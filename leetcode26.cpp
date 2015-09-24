// leetcode26.cpp : 定义控制台应用程序的入口点。
//
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//It doesn't matter what you leave beyond the new length.
#include "stdafx.h"

int removeDuplicates(int* nums, int numsSize) {
	if (nums == NULL || numsSize == 0) return 0;
	int current = nums[0];
	int result = 1;
	for (int i = 1; i < numsSize;i++)
	{
		if (current == nums[i])
		{
		}
		else
		{
			current = nums[i];
			nums[result++] = nums[i];
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

