#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        printf("%d %d %d\n", left, right, mid);
        if (nums[mid] == target)
            return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[10] = {3,1};
    printf("%d\n", search(nums, 2, 1));
}
