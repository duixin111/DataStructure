#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>
#include "Stack.h"
#include "MySort.h"
#include "Heap.h"


//稳定  时间复杂度：O(n^2)  空间复杂度：O(1)
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int end = i - 1;
		int tmp = array[i];
		while (tmp >= 0 && tmp < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = tmp;
	}
}

//不稳定  时间复杂度：O(n log n)~O(n^2)   空间复杂度:O(1)
void ShellSort(int array[], int size)
{
	int interval = size;
	while (interval > 1)
	{
		interval = interval / 3 + 1;
		for (int i = interval; i < size; i++)
		{
			int end = i - interval;
			int tmp = array[i];
			while (end >= 0 && tmp < array[end])
			{
				array[end + interval] = array[end];
				end -= interval;
			}
			array[end + interval] = tmp;
		}
	}
}




//稳定  时间复杂度：O(n^2)  空间复杂度：O(1)
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int max = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[j] > array[max])
				max = j;
		}
		if (max != size - i - 1)
			Swap(&array[max], &array[size - i - 1]);
	}
}

int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

int Quick(int array[], int left, int right)
{

	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];

	while (begin < end)
	{
		//找比基准值大的值的下标
		while (begin < end && array[begin] <= key)
			begin++;
		//找比基准值小的值的下标
		while (begin < end && key <= array[end])
			end--;
		//交换
		if (begin < end)
			Swap(&array[begin], &array[end]);
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

//递归版本
void QuickSort(int array[], int left, int right)
{
	int div = 0;
	if (right - left <= 16)
		InsertSort(array + left, right - left);
	else
	{
		div = Quick(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div, right);
	}
}
//非递归
void QuickSortNor(int array[], int size)
{
	Stack s;
	StackInit(&s);
	int left = 0;
	int right = size;

	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		right = StackTop(&s);
		StackPop(&s);
		left = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Quick(array, left, right);

			// [div+1, right)
			StackPush(&s, div + 1);
			StackPush(&s, right);

			// [left, div)
			StackPush(&s, left);
			StackPush(&s, div);
		}
	}

	StackDestroy(&s);
}


void CountSort(int array[], int size)
{
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] < minValue)
			minValue = array[i];
		if (maxValue < array[i])
			maxValue = array[i];
	}
	int str = maxValue - minValue + 1;
	int* arr = (int*)calloc(str, sizeof(array[0]));
	if (arr == NULL)
		return;
	for (int i = 0; i < size; i++)
		arr[array[i] - minValue]++;


	for (int i = 0, j = 0; i < str; i++, j++)
	{
		while (arr[i]--)
			array[j] = i + minValue;
	}

	free(arr);
}
#if 0
void HeapAdjust(int array[], int size, int parent)
{
	// 标记左孩子
	int child = parent * 2 + 1;

	while (child < size)
	{
		// 判断有无右孩子
		// 有右孩子，比较，找出较大孩子
		if (child + 1 < size && array[child + 1] > array[child])
		{
			child += 1;
		}

		// 双亲是小于较大孩子，交换
		if (array[child] > array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int array[], int size)
{
	int end = size - 1;

	//建堆
	for (int root = ((size - 2) >> 1); root >= 0; root--)
	{
		HeapAdjust(array, size, root);
	}

	//堆删除，排序
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}
#endif

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; i++)
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
	}
}

void MergeData(int array[], int left, int mid, int right, int tmp[])
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[index++] = array[begin1++];
		else
			tmp[index++] = array[begin2++];
	}

	while (begin1 < end1)
		tmp[index++] = array[begin1++];

	while (begin2 < end2)
		tmp[index++] = array[begin2++];
}
void _MergeSort(int array[], int left, int right, int tmp[])
{
	if (right - left <= 16)
		InsertSort(array + left, right + left);
	else
	{
		int mid = left + ((right - left) >> 1);
		//[left, mid)
		_MergeSort(array, left, mid, tmp);
		//[mid, right)
		_MergeSort(array, mid, right, tmp);
		//归并
		MergeData(array, left, mid, right, tmp);

		memcpy(array + left, tmp + left, sizeof(array[0]) * (right - left));
	}
}

void MergeSort(int array[], int size)
{
	int* tmp = (int*)malloc(sizeof(array[0]) * size);
	if (tmp == NULL)
	{
		printf("开辟空间失败！");
		return;
	}
	_MergeSort(array, 0, size, tmp);
	free(tmp);
}

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

