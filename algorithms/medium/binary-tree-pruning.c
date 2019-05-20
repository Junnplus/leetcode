#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val, struct TreeNode* left, struct TreeNode* right) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right=right;
    return node;
}

void prune(struct TreeNode* root) {
    if (root == NULL)
        return;
    prune(root->left);
    prune(root->right);
    if (root->left && root->left->val == -1)
        root->left = NULL;
    if (root->right && root->right->val == -1)
        root->right = NULL;
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        root->val = -1;
    }
}

struct TreeNode* pruneTree(struct TreeNode* root){
    prune(root);
    if (root->val == -1)
        return NULL;
    return root;
}

void printTree(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    struct TreeNode *n1 = newNode(1, NULL, NULL);
    struct TreeNode *n2 = newNode(0, NULL, NULL);
    struct TreeNode *n3 = newNode(0, n2, n1);
    struct TreeNode *n8 = newNode(0, NULL, NULL);
    struct TreeNode *n5 = newNode(1, n8, NULL);
    struct TreeNode *n6 = newNode(1, NULL, NULL);
    struct TreeNode *n7 = newNode(1, n5, n6);
    struct TreeNode *n4 = newNode(1, n7, n3);
    n4 = pruneTree(n4);
    printTree(n4);
}
