// leetcode7.cpp : �������̨Ӧ�ó������ڵ㡣
//
//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
#include "stdafx.h"
#include "limits.h"

int reverse(int x) {
	long long int result = 0;
	do
	{
		result = result * 10 + x % 10;
		x = x / 10;
	} while (x);
	if (result > INT_MAX || result < INT_MIN)
	{
		result = 0;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	long int x = reverse(100000003);
	printf("%ld\n",x);
	return 0;
}

