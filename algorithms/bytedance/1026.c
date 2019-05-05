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

int findPath(struct TreeNode* root, struct TreeNode* o, struct TreeNode** path) {
    if (root == NULL)
        return 0;
    *path++ = root;
    if (root == o) {
        *path = NULL;
        return 1;
    }
    if (findPath(root->left, o, path) == 1)
        return 1;
    
    if (findPath(root->right, o, path) == 1)
        return 1;
    *path-- = NULL;
    return 0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* p1[MAXLEN];
    struct TreeNode* p2[MAXLEN];
    findPath(root, p, p1);
    findPath(root, q, p2);
    struct TreeNode **c1 = p1, **c2= p2, *r = NULL;
    while (*c1 != NULL && *c2 != NULL) {
        printf("%d %d\n", (*c1)->val, (*c2)->val);
        if (*c1 == *c2) {
            r = *c1;
        }
        c1++;
        c2++;
    }
    return r;
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
    root = lowestCommonAncestor(node3, node7, node4);
    printf("%d\n", root->val);
}
