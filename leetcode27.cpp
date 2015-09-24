// leetcode27.cpp : 定义控制台应用程序的入口点。
//
//Given an array and a value, 
//remove all instances of that value in place and return the new length.
//
//The order of elements can be changed.
//It doesn't matter what you leave beyond the new length.
#include "stdafx.h"
int removeElement(int* nums, int numsSize, int val) {
	if (nums == NULL || numsSize == 0) return 0;
	int end = numsSize - 1;
	//int result = numsSize;
	for (int i = 0; i < numsSize;i++)
	{
		if (nums[i] == val)
		{
			numsSize--;
			while (nums[end] == val && i != end)
			{
				numsSize--;
				end--;
				if (i == end) return numsSize;
			}
			int temp = nums[end];
			nums[end] = nums[i];
			nums[i] = temp;
			end--;
		}
	}
	return numsSize;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

