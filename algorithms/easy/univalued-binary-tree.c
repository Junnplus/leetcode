#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isUnivalTree(struct TreeNode* root){
    if (root == NULL)
        return true;
    if (root->left != NULL && root->val != root->left->val)
        return false;
    if (root->right != NULL && root->val != root->right->val)
        return false;
    bool unival;
    unival = !isUnivalTree(root->left) || !isUnivalTree(root->right);
    if (unival)
        return !unival;
    return true;
}

int main() {
    root = newTree(2, newTree(2, newTree(2, NULL, NULL), newTree(2, NULL, NULL)), newTree(2, NULL, NULL));
    printf("%d\n", isUnivalTree(root));
}
