// leetcode1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<limits.h>
//int *twoSum(int numbers[], int n, int target)
//{
//	if ((numbers == NULL) | (n < 2))
//	{
//		return NULL;
//	}
//	int index1;
//	int index2;
//	int* ret = (int*)malloc(sizeof(int)* 2);
//	for (index1 = 0; index1 < n; ++index1)
//	{
//		for (index2 = index1 + 1; index2 < n; ++index2)
//		{
//			int sum_tmp = numbers[index1] + numbers[index2];
//			if (sum_tmp == target)
//			{
//				ret[0] = index1 + 1;
//				ret[1] = index2 + 1;
//				return ret;
//			}
//		}
//	}
//	return NULL;
//}
//int main(void)
//{
//	int array[] = { 1, 7, 11, 15 };
//	int n = sizeof(array) / sizeof(int);
//	int target = 9;
//	int* result = twoSum(array, (int)n, target);
//	printf("The index1: %d; the index2: %d\n", result[0], result[1]);
//	free(result);
//}
//void quickSort(int *a, int left, int right);
//void print(int *a,int size)
//{
//	for (int i = 0; i < size;i++)
//	{
//		printf("%d,",a[i]);
//	}
//}

//int* twoSum(int* nums, int numsSize, int target) {
//	if ((nums == NULL) | (numsSize < 2)){
//		return NULL;
//	}
//	print(nums,numsSize);
//	puts("");
//	quickSort(nums,0,numsSize-1);
//	print(nums,numsSize);
//	int index1 = 1;
//	int index2 = numsSize;
//	int *first = &nums[0];
//	int *last = &nums[numsSize-1];
//	int *ret = (int*)malloc(sizeof(int)* 2);
//	if (ret == NULL){}
//	while (first != last)
//	{
//		if (*first + *last == target)
//		{
//			ret[0] = index1;
//			ret[1] = index2;
//			return ret;
//		}
//		else
//		{
//			if (*first + *last > target)
//			{
//				index2--;
//				last = last - 1;
//			}
//			else if (*first + *last < target)
//			{
//				index1++;
//				first = first + 1;
//			}
//		}
//	}
//	return NULL;
//}
//
//void quickSort(int *a,int left,int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int sizeL = left;
//	int sizeR = right;
//	int *l = &a[left];
//	int *r = &a[right];
//	int key = a[left];
//	while (left < right)
//	{
//		while (left < right && key < *r)
//		{
//			right--;
//			r--;
//		}
//		*l = *r;
//
//		while (left < right && key > *l)
//		{
//			l++;
//			left++;
//		}
//		*r = *l;
//	}
//	*l = key;
//	quickSort(a,sizeL,left-1);
//	quickSort(a, left+1, sizeR);
//}

//int* twoSum(int* nums, int numsSize, int target) 
//{
//	int min = INT_MAX;
//	int i;
//	for (i = 0; i < numsSize; i++)
//	{
//		min = min < nums[i] ? min : nums[i];
//	}
//	target -= 2 * min;
//	int *index = (int *)calloc(target+1,sizeof(int));
//	int *re = (int *)calloc(2,sizeof(int));
//	for (i = 0; i < numsSize; i++)
//	{
//		int left = nums[i] - min;
//		if (target < left)
//		{
//			continue;
//		}
//		if (index[target - left] == 0)
//		{
//			index[left] = i + 1;
//			continue;
//		}
//
//		re[0] = index[target - left];
//		re[1] = i + 1;
//		break;
//	}
//	free(index);
//	return re;
//}

typedef struct HashNode{
	int key;
	int value;
}HashNode;

typedef struct HashMap{
	int size;
	HashNode** storage;
}HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap,int key,int vaule);
HashNode* hash_get(HashMap* hashMap,int key);

HashMap* hash_create(int size)
{
	HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
	hashMap->size = size;
	hashMap->storage = (HashNode**)calloc(size,sizeof(HashNode*));
	return hashMap;
}
void hash_destroy(HashMap* hashMap)
{
	for (int i = 0; i < hashMap->size;i++)
	{
		HashNode *node;
		if (node = hashMap->storage[i])
		{
			free(node);
		}
	}
	free(hashMap->storage);
	free(hashMap);
}

void hash_set(HashMap* hashMap, int key, int value)
{
	int hash = abs(key) % hashMap->size;
	HashNode* node;
	while (node = hashMap->storage[hash])
	{
		if (hash < hashMap->size - 1)
		{
			hash++;
		}
		else
		{
			hash = 0;
		}
	}
	node = (HashNode*)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap* hashMap, int key)
{
	int hash = abs(key) % hashMap->size;
	HashNode* node;
	while (node = hashMap->storage[hash])
	{
		if (node->key == key)
		{
			return node;
		}
		if (hash < hashMap->size - 1)
		{
			hash++;
		}
		else
		{
			hash = 0;
		}
	}
}

int* twoSum(int* nums, int numsSize, int target)
{
	HashMap* hashMap;
	HashNode* node;
	int rest, i;

	hashMap = hash_create(numsSize);
	for (i = 0; i < numsSize;i++)
	{
		rest = target - nums[i];
		node = hash_get(hashMap,rest);
		if (node) {
			int* result = (int*)malloc(sizeof(int)* 2);
			result[0] = node->value + 1;
			result[1] = i + 1;
			hash_destroy(hashMap);
			return result;
		}
		else {
			hash_set(hashMap, nums[i], i);
		}
	}
}

int main(int argc, char **argv)
{
	int array[] = {2,5,7,11};
	int n = sizeof(array) / sizeof(int);
	int target = 9;
	int* result = twoSum(array, n, target);
	if (result != NULL)
	{
		printf("The index1: %d; the index2: %d\n", result[0], result[1]);
	}
	free(result);
}