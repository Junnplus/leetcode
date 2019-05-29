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

int maxDepth(struct TreeNode* root){
    if (root == NULL)
        return 0;
    int lm = maxDepth(root->left) + 1;
    int rm = maxDepth(root->right) + 1;
    return lm > rm? lm: rm;
}

int main() {
    struct TreeNode *n15 = newNode(15, NULL, NULL);
    struct TreeNode *n7 = newNode(7, NULL, NULL);
    struct TreeNode *n20 = newNode(20, n15, n7);
    struct TreeNode *n9 = newNode(9, NULL, NULL);
    struct TreeNode *n3 = newNode(3, n9, n20);
    printf("%d\n", maxDepth(n3));
}
