#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root;

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;
    int mid = numsSize / 2;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    if (numsSize == 1) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    node->left = sortedArrayToBST(nums, mid - 1 + 1);
    node->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    return node;
}

void printTree(struct TreeNode *root) {
    if (root == NULL) {
        printf("null\n");
        return;
    }
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    root = sortedArrayToBST(nums, 5);
    printf("\n");
    printTree(root);
}
