// leetcode20.cpp : 定义控制台应用程序的入口点。
//
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//The brackets must close in the correct order, 
//"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include "stdafx.h"
#include "string.h"
bool isValid(char* s) {
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		switch (s[i])
		{
		case '[':
			if (s[++i] == ']')
				i++;
			else return false;
			break;
		case '(':
			if (s[++i] == ')')
				i++;
			else return false;
			break;
		case '{':
			if (s[++i] == '}')
				i++;
			else return false;
			break;
		default:
			return false;
		}
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* test = "()[]{}";
	printf("%d\n",isValid(test));
	return 0;
}

