#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findFirst(int* nums, int target, int numsSize) {
    int start = 0;
    int end = numsSize - 1;
    while (start <= end)  {
        int mid = (start + end) / 2;
        if (nums[mid]>=target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (start >=0 && start < numsSize && nums[start] == target)
        return start;
    else
        return -1;
}

int findLast(int* nums, int target, int numsSize) {
    int start = 0;
    int end = numsSize - 1;
    while (start <= end)  {
        int mid = (start + end) / 2;
        if (nums[mid]>target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (end >=0 && end < numsSize && nums[end] == target)
        return end;
    else
        return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *p=malloc(sizeof(int) * 2);
    *p = -1;
    *(p+1) = -1;
    if (numsSize == 0)
        return p;
    *p = findFirst(nums, target, numsSize);
    *(p+1) = findLast(nums, target, numsSize);
    printf("%d %d\n", *p, *(p+1));
    return p;
}

int main() {
    int nums[6] = {5,7,7,8,8,10};
    int rs;
    searchRange(nums, 6, 7, &rs);
}
