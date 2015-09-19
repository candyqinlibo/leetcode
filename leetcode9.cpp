// leetcode9.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Determine whether an integer is a palindrome(���ĶԳ�).Do this without extra space.
#include "stdafx.h"
#include "limits.h"
bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x < 10) return true;
	long long int result = 0;
	int temp = x;
	do
	{
		result = result * 10 + x % 10;
		x = x / 10;
	} while (x);
	if (result > INT_MAX || result < INT_MIN)
	{
		result = 0;
	}
	return temp == result;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d\n",isPalindrome(12321));
	return 0;
}
