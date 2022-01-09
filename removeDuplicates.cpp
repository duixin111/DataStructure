#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;
    int fast = 1, slow = 1;
    while (fast < numsSize)
    {
        if (nums[fast] != nums[fast - 1])
            nums[slow++] = nums[fast];
        fast++;
    }

    return slow;
}
int main()
{
    int num[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int size = sizeof(num) / sizeof(num[0]);
    int numSize = removeDuplicates(num, size);
    for (int i = 0; i < numSize; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}