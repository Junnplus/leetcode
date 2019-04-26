#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root;

struct TreeNode* newTree(int val, struct TreeNode *left, struct TreeNode *right) {
    struct TreeNode *node;
    node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

void printTree(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int mid = *preorder, i;
    struct TreeNode *node;
    if (preorderSize == 0)
        return NULL;
    for (i = 0; i < inorderSize; i ++) {
        if ( *(inorder +i) ==mid)
            break;
    }
    node = newTree(mid, NULL, NULL);
    if (inorderSize == 1)
        return node;
    if (i>0)
        node->left = buildTree(preorder + 1, i, inorder, i);
    if (preorderSize -i-1 > 0)
        node->right = buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);
    return node;
}

int main() {
    int preorder[] = {1,2};
    int inorder[] = {2,1};
    root = buildTree(preorder, 2, inorder, 2);
    printTree(root);

    printf("\n");
    int preorder1[] = {3,1,2,4};
    int inorder1[] = {1,2,3,4};
    root = buildTree(preorder1, 4, inorder1, 4);
    printTree(root);
}
