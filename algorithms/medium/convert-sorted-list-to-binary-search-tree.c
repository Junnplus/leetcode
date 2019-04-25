#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct ListNode *head;
struct TreeNode *node;

struct ListNode* newNode(int val, struct ListNode *next) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = next;
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode *pmid, *tail, *mid;
    pmid = newNode(-1, head);
    mid = tail = head;
    if (head == NULL) {
        return NULL;
    }
    while (tail != NULL && tail->next != NULL) {
        tail = tail->next->next;
        mid = mid->next;
        pmid = pmid->next;
    }
    struct TreeNode *node;
    node = malloc(sizeof(struct TreeNode));
    node->val = mid->val;
    if (head == mid) {
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    pmid->next = NULL;
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(mid->next);
    return node;
}

void printTree(struct TreeNode *root) {
    if (root == NULL)
        return;
    printf("%d\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    head = newNode(-10, newNode(-3, newNode(0, newNode(5, newNode(9, NULL)))));
    node = sortedListToBST(head);
    printTree(node);
}
