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

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    struct TreeNode *root, *t1left, *t2left, *t1right, *t2right;
    if (t1 == NULL && t2 == NULL)
        return NULL;
    root = malloc(sizeof(struct TreeNode));
    root->val = 0;
    if (t1 != NULL)
        root->val += t1->val;
    if (t2 != NULL)
        root->val += t2->val;

    if (t1 == NULL) {
        t1left = NULL;
        t1right = NULL;
    } else {
        t1left = t1->left;
        t1right = t1->right;
    }

    if (t2 == NULL) {
        t2left = NULL;
        t2right = NULL;
    } else {
        t2left = t2->left;
        t2right = t2->right;
    }

    root->left = mergeTrees(t1left, t2left);
    root->right = mergeTrees(t1right, t2right);
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

int main() {
    t1 = newTree(1, newTree(3, newTree(5, NULL, NULL), NULL), newTree(2, NULL, NULL));
    t2 = newTree(2, newTree(1, NULL, newTree(4, NULL, NULL)), newTree(3, NULL, newTree(7, NULL, NULL)));
    root = mergeTrees(t1, t2);
    printTree(root);
}
