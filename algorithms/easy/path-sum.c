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


bool _hasPathSum(struct TreeNode *root, int curSum, int sum) {
    if (root != NULL && root->left == NULL && root->right == NULL && curSum + root->val == sum)
        return true;
    if (root->left != NULL && _hasPathSum(root->left, curSum + root->val, sum))
        return true;
    if (root->right != NULL && _hasPathSum(root->right, curSum + root->val, sum))
        return true;
    return false;
}


bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL)
        return false;
    return _hasPathSum(root, 0, sum);
}

int main() {
    struct TreeNode *n15 = newNode(15, NULL, NULL);
    struct TreeNode *n7 = newNode(7, NULL, NULL);
    struct TreeNode *n20 = newNode(20, n15, n7);
    struct TreeNode *n9 = newNode(9, NULL, NULL);
    struct TreeNode *n3 = newNode(3, n9, n20);
    printf("%d\n", hasPathSum(n3, 12));
}
