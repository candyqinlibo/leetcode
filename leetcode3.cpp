// leetcode3.cpp : 定义控制台应用程序的入口点。
//
//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
//which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
#include "stdafx.h"
#include "string.h"

int lengthOfLongestSubstring(char* s)
{
	int len = 0;
	char *end = s, *temp;
	char* addressTable[128] = { NULL };
	while (*end){
		temp = addressTable[*end];
		addressTable[*end] = end;
		if (temp >= s){
			len = end - s>len ? end - s : len;
			s = temp + 1;
		}end++;
	}
	len = end - s>len ? end - s : len;
	return len;
}

int main(void)
{
	char* s = "agrahhsagrtjr";
	int length = lengthOfLongestSubstring(s);
	printf("%d\n",length);
	return 0;
}

