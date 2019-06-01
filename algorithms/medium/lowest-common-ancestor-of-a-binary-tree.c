#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLEN 100000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root;

struct TreeNode* newNode(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    struct TreeNode *left, * right;
    left = lowestCommonAncestor(root->left, p, q);
    right = lowestCommonAncestor(root->right, p, q);
    return left == NULL? right : right == NULL ? left : root;
}

int main() {
    struct TreeNode *node4 = newNode(4, NULL, NULL);
    struct TreeNode *node7 = newNode(7, NULL, NULL);
    struct TreeNode *node0 = newNode(0, NULL, NULL);
    struct TreeNode *node8 = newNode(8, NULL, NULL);
    struct TreeNode *node2 = newNode(2, node7, node4);
    struct TreeNode *node1 = newNode(1, node0, node8);
    struct TreeNode *node6 = newNode(6, NULL, NULL);
    struct TreeNode *node5 = newNode(5, node6, node2);
    struct TreeNode *node3 = newNode(3, node5, node1);
    root = lowestCommonAncestor(node3, node6, node4);
    printf("%d\n", root->val);
}
