// leetcode58LengthOfLastWord.cpp : 定义控制台应用程序的入口点。
//
//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//For example,
//Given s = "Hello World",
//return 5.
#include "stdafx.h"
#include "string.h"
int lengthOfLastWord(char* s) {
	if (s == NULL) return 0;
	int pos = strlen(s)-1;
	int result = 0;
	while (pos > 0 && s[pos] == ' ') pos--;
	while (pos >= 0 && s[pos] != ' ')
	{
		pos--;
		result++;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

