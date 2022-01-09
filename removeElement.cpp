#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {

	int left = 0;
	for (int right = 0; right < numsSize; right++)
	{
		if (nums[right] != val)
		{
			nums[left++] = nums[right];
		}
	}

	return left;
}
int main()
{
	int num[] = { 3,2,2,3 };
	int n = sizeof(num) / sizeof(num[0]);
	int nums = removeElement(num, n, 2);
	for (int i = 0; i < nums; i++)
		printf("%d ", num[i]);
	return 0;
}