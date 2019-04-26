#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root, *t1, *t2;

struct TreeNode* newTree(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = left;
    root->right = right;
    return root;
}

void printTree(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;
    if (root->val == val)
        return root;
    struct TreeNode *node;
    node = searchBST(root->left, val);
    if (node != NULL)
        return node;
    node = searchBST(root->right, val);
    if (node != NULL)
        return node;
    return NULL;
}

int main() {
    root = newTree(4, newTree(2, newTree(1, NULL, NULL), newTree(3, NULL, NULL)), newTree(7, NULL, NULL));
    t1 = searchBST(root, 2);
    printTree(t1);
}
