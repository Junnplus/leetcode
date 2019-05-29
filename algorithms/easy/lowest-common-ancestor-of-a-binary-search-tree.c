#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root;

struct TreeNode* newNode(int val, struct TreeNode* left, struct TreeNode* right) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL)
        return NULL;
    if (p->val <= root->val && root->val <= q->val)
        return root;
    if (q->val <= root->val && root->val <= p->val)
        return root;
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return NULL;
}

int main() {
    struct TreeNode *node5 = newNode(5, NULL, NULL);
    struct TreeNode *node3 = newNode(3, NULL, NULL);
    struct TreeNode *node4 = newNode(4, node3, node5);
    struct TreeNode *node0 = newNode(0, NULL, NULL);
    struct TreeNode *node2 = newNode(2, node0, node4);
    struct TreeNode *node7 = newNode(7, NULL, NULL);
    struct TreeNode *node9 = newNode(9, NULL, NULL);
    struct TreeNode *node8 = newNode(8, node7, node9);
    struct TreeNode *node6 = newNode(6, node2, node8);
    // [6,2,8,0,4,7,9,null,null,3,5]
    root = lowestCommonAncestor(node6, node8, node2);
    printf("%d\n", root->val);

    root = lowestCommonAncestor(node6, node3, node5);
    printf("%d\n", root->val);
}
