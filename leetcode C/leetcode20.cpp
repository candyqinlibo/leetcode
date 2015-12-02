// leetcode20.cpp : 定义控制台应用程序的入口点。
//
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//The brackets must close in the correct order, 
//"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include "stdafx.h"
#include "string.h"
#include "malloc.h"
bool isValid(char* s) {
	int length = strlen(s);
	char* temp = (char*)malloc((length+1)*sizeof(char));
	int count = -1;
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			temp[++count] = s[i];			
		}
		else
		{
			switch (temp[count])
			{
			case '(':
				if (s[i] == ')')
				{
					temp[count] = 0;
					count--;
				}
				else
				{
					return false;
				}
				break;
			case '{':
				if (s[i] == '}')
				{
					temp[count] = 0;
					count--;
				}
				else
				{
					return false;
				}
				break;
			case '[':
				if (s[i] == ']')
				{
					temp[count] = 0;
					count--;
				}
				else
				{
					return false;
				}
				break;
			default:
				return false;
			}
		}
	}
	if (count == -1)return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* test = "()[]{}";
	printf("%d\n",isValid(test));
	return 0;
}

