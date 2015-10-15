// leetcode38CountAndSay.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "malloc.h"

char* countAndSay(int n){
	if (n == 1) return "1";
	char *cur = (char*)malloc(2*sizeof(char));
	char* tmp;
	cur[0] = '1';
	cur[1] = 0;

	int len, idx, j, count;
	for (int i = 1; i < n;i++)
	{
		len = strlen(cur);
		tmp = (char*)calloc(len*2+1,sizeof(char));
		count = 1;
		for (idx = 1,j=0;idx < len; idx++)
		{
			if (cur[idx] == cur[idx-1])
			{
				count++;
			}
			else
			{
				tmp[j++] = '0' + count;
				tmp[j++] = cur[idx - 1];
				count = 1;
			}
		}
		tmp[j++] = '0' + count;
		tmp[j++] = cur[len - 1];
		free(cur);
		cur = tmp;
	}
	return cur;
}

//char* countAndSay(int n) {
//	if (n < 1) return NULL;
//	if (n = 1) return "1";
//	char* result = (char*)malloc(2*sizeof(char));
//	if (result == NULL) return NULL;
//	result[0] = '1';
//	result[1] = '0';
//	int key, count,pos;
//	for (int i = 1; i < n;i++)
//	{
//		int length = strlen(result);
//		char* temp = (char*)malloc((length*2+1)*sizeof(char));
//		char* x = result;
//		//temp = result;
//		pos = 0;
//		key = x[0];
//		count = 1;
//		for (int j = 1; j < length;j++)
//		{
//			if (x[j] == key)
//			{
//				count++;
//			}
//			else
//			{
//				x[pos++] = count + '0';
//				count = 1;
//				x[pos++] = key + '0';
//				key = x[j];
//			}
//		}
//		temp[pos++] = count + '0';
//		temp[pos++] = key + '0';
//		temp[pos] = '\0';
//		result = temp;
//	}
//	return result;
//}

int main(void)
{
	puts(countAndSay(10));
	return 0;
}

