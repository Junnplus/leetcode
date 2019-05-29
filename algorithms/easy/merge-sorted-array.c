#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int len = m + n;
    while (m>0 && n>0) {
        //printf("%d %d\n", nums1[m-1], nums2[n-1]);
        if (nums1[m-1] > nums2[n-1]) {
            nums1[--len] = nums1[--m];
        } else {
            nums1[--len] = nums2[--n];
        }
    }
    while (m > 0) {
        nums1[--len] = nums1[--m];
    }
    while (n > 0) {
        nums1[--len] = nums2[--n];
    }
}

int main() {
    int nums1[10] = {1,2,3,0,0,0}, m = 3;
    int nums2[10] = {2,5,6}, n = 3;
    merge(nums1, 6, m, nums2, 3, n);
    for (int i=0;i < m+n; i++) {
        printf("%d\n", nums1[i]);
    }
}
