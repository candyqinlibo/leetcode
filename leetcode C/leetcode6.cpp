// leetcode6.cpp : 定义控制台应用程序的入口点。
//

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
//(you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include "stdafx.h"
#include "string.h"
#include "malloc.h"
char* convert(char* s, int numRows) 
{
	int length = strlen(s);
	char* result = (char*)malloc((length+1)*sizeof(char));
	int count = 0;
	if (numRows == 1 || numRows >= length)
	{
		result = s;
	}
	else
	{
		for (int i = 1; i <= numRows; i++)
		{
			for (int j = i; j <= length; j += 2 * numRows - 2)
			{
				result[count++] = s[j - 1];
				if (i != 1 && i != numRows && j + 2 * (numRows - i) <= length)
				{
					result[count++] = s[j + 2 * (numRows - i) - 1];
				}
			}
		}
		result[count] = '\0';
	}
	return result;
}

int main()
{
	char* s = "PAYPALISHIRING";
	char* newString = convert(s,4);
	puts(newString);
	free(newString);
	return 0;
}