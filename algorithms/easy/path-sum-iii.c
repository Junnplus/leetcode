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


int pathSumWithRoot(struct TreeNode *root, int sum) {
    if (root == NULL)
        return 0;
    int r = pathSumWithRoot(root->left, sum - root->val) + pathSumWithRoot(root->right, sum - root->val);
    if (sum == root->val)
        r ++;
    return r;
}

int pathSum(struct TreeNode* root, int sum){
    if (root == NULL)
        return 0;
    return pathSumWithRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}



int main() {
    struct TreeNode *n15 = newNode(15, NULL, NULL);
    struct TreeNode *n7 = newNode(7, NULL, NULL);
    struct TreeNode *n20 = newNode(9, n15, n7);
    struct TreeNode *n9 = newNode(9, NULL, NULL);
    struct TreeNode *n3 = newNode(3, n9, n20);
    printf("%d\n", pathSumWithRoot(n3, 12));
}
