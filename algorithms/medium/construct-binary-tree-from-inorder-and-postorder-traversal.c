#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
    if (root == NULL) {
        printf("null\n");
        return;
    }
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int mid = *(postorder + postorderSize -1), i;
    struct TreeNode *node;
    if (inorder == NULL || postorder == NULL || inorderSize == 0)
        return NULL;
    for (i = 0; i< inorderSize; i++)
        if ( *(inorder + i) == mid)
            break;
    node = newTree(mid, NULL, NULL);
    if (i > 0)
        node->left = buildTree(inorder, i, postorder, i);
    if (inorderSize -i - 1 > 0)
        node->right = buildTree(inorder + i + 1, inorderSize - i - 1, postorder + i, inorderSize - i - 1);
    return node;
}


int main() {
    int postorder[] = {9,15,7,20,3};
    int inorder[] = {9,3,15,20,7};
    root = buildTree(inorder, 5, postorder, 5);
    printTree(root);
}
