#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root;

struct TreeNode* newTree(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *node;
    node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
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

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    int i = 0;
    if (preorderSize == 0)
        return NULL;
    int mid = *preorder;
    struct TreeNode *node;
    node = newTree(mid, NULL, NULL);
    if (preorderSize == 1) {
        return node;
    }

    for (i = 1; i < preorderSize; i++) {
        if ( *(preorder +i) > mid)
            break;
    }
    node->left = bstFromPreorder(preorder+1, i-1);
    node->right = bstFromPreorder(preorder+i, preorderSize-i);
    return node;
}

int main() {
    int nums[] = {8,5,1,7,10,12};
    root = bstFromPreorder(nums, 6);
    printTree(root);
}
