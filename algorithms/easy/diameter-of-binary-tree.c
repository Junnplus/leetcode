#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *newNode(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

int deepth(struct TreeNode *root, int *maxPath) {
    if (root == NULL)
        return 0;
    int lDeepth = deepth(root->left, maxPath) + 1;
    int rDeepth = deepth(root->right, maxPath) + 1;
    if (lDeepth + rDeepth > *maxPath) {
        *maxPath = lDeepth + rDeepth - 1;
    }
    return lDeepth > rDeepth ? lDeepth : rDeepth;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int maxPath = 0;
    if (root == NULL)
        return 0;
    deepth(root, &maxPath);
    return maxPath - 1;
}

int main() {
    struct TreeNode *n15 = newNode(15, NULL, NULL);
    struct TreeNode *n7 = newNode(7, NULL, NULL);
    struct TreeNode *n20 = newNode(20, NULL, NULL);
    struct TreeNode *n9 = newNode(9, NULL, NULL);
    struct TreeNode *n3 = newNode(3, n9, n20);
    printf("%d\n", diameterOfBinaryTree(NULL));
}
