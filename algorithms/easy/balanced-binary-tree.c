#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int deepth(struct TreeNode *root, bool *r) {
    if (root == NULL)
        return 0;
    int ldeepth = deepth(root->left, r) + 1;
    int rdeepth = deepth(root->right, r) + 1;
    if (ldeepth - rdeepth > 1 || rdeepth - ldeepth > 1) {
        *r = false;
    }
    return ldeepth > rdeepth? ldeepth: rdeepth;
}

bool isBalanced(struct TreeNode* root){
    bool r = true;
    deepth(root, &r);
    return r;
}

int main() {
    struct TreeNode *n16 = newNode(16, NULL, NULL);
    struct TreeNode *n15 = newNode(15, NULL, n16);
    struct TreeNode *n7 = newNode(7, NULL, NULL);
    struct TreeNode *n20 = newNode(20, n15, n7);
    struct TreeNode *n9 = newNode(9, NULL, NULL);
    struct TreeNode *n3 = newNode(3, n9, n20);
    printf("%d\n", isBalanced(n3));
}
