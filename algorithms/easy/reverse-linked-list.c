#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int val, struct ListNode *next) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = next;
    return node;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode *reversed = NULL;

    while (head != NULL) {
        printf("%d ", head->val);
        if (reversed == NULL) {
            reversed = newNode(head->val, NULL);
        } else {
            struct ListNode *node = newNode(head->val, reversed);
            reversed = node;
        }
        head = head->next;
    }
    return reversed;
}


int main() {
    struct ListNode *l1 = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    struct ListNode *l2 = reverseList(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");
}
