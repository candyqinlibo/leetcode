// leetcode13.cpp : 定义控制台应用程序的入口点。
//
//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.
#include "stdafx.h"
#include "string.h"
int romanToInt(char* s) {
	int N = strlen(s);
	int map[26] = { 0 };
	map['I' - 'A'] = 1;
	map['V' - 'A'] = 5;
	map['X' - 'A'] = 10;
	map['L' - 'A'] = 50;
	map['C' - 'A'] = 100;
	map['D' - 'A'] = 500;
	map['M' - 'A'] = 1000;
	// main loop
	int sum = 0;
	for (int i = 0; i<N; i++){
		// check IV, IX, XL, XC, CD, CM
		if (i != N - 1){
			int n = map[s[i] - 'A'];
			int nn = map[s[i + 1] - 'A'];
			if (n<nn){
				sum += (nn - n);
				i++;
			}
			else{
				sum += n;
			}
		}
		else
			sum += map[s[i] - 'A'];
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d\n", romanToInt("IV"));
	return 0;
}

