#include <stdio.h>
#include <stdlib.h>

int partition(int *nums, int start, int end) {
    if (start >= end)
        return start;
    int v = nums[start], i = start, j = end, tmp;
    while (i != j) {
        while (i < j && nums[j] >= v)
            j --;
        while (i < j && nums[i] <= v)
            i ++;
        if (i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        printf("%d,%d\n", i,j);
    }
    nums[start] = nums[i];
    nums[i] = v;
    return i;
}

int majorityElement(int* nums, int numsSize){
    int start =0, end = numsSize - 1;
    int index = partition(nums, start, end);
    int mid = numsSize / 2;
    while (index != mid) {
        printf("%d,\n", index);
        if (index > mid) {
            end = index - 1;
            index = partition(nums, start, end);
        }
        else {
            start = index + 1;
            index = partition(nums, start, end);
        }
    }
    return nums[mid];
}


int main() {
    int nums1[5] = {6,6,6,7,7};
    printf("%d\n", majorityElement(nums1, 5));
}
