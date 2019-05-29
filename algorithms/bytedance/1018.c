#include <stdio.h>

int p(int *nums, int left, int right) {
    int i = left, j = right, tmp;
    int v = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= v)
            j --;
        while (i < j && nums[i] <= v)
            i ++;
        if (i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    nums[left] = nums[i];
    nums[i] = v;
    return i;
}


int findKthLargest(int* nums, int numsSize, int k){
    int index, left = 0, right = numsSize - 1;
    k = numsSize - k;
    while (left <= right) {
        index = p(nums, left, right);
        if (index == k)
            return nums[index];
        if (index < k) {
            left = index + 1;
        } else {
            right = index - 1;
        }
    }
    return -1;
}


int main() {
    int nums[10] = {3,2,3,1,2,4,5,5,6};
    printf("%d\n", findKthLargest(nums, 9, 9));
}
