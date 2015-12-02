// leetcode8.cpp : 定义控制台应用程序的入口点。
//
//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.
//If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes : It is intended for this problem to be specified vaguely(ie, no given input specs).
//You are responsible to gather all the input requirements up front.
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"
int myAtoi(char* str) {
	int res = 0;
	int flag = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')str++;
	if (*str == '-') {
		flag = -1;
		str++;
	}
	else if (*str == '+') {
		str++;
	}
	while (*str == '0')str++;
	while (*str >= '0'&&*str <= '9') {
		if (res > INT_MAX / 10 || res * 10 > INT_MAX - (*str - '0')) {
			if (flag == 1) return INT_MAX;
			else return INT_MIN;
		}
		res = res * 10 + (*str - '0');
		str++;
	}
	return flag*res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d\n",myAtoi("+-4"));
	return 0;
}

