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

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode *cur = head;
    while (cur != NULL) {
        if (cur->next != NULL && cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    struct ListNode *l1 = newNode(2, newNode(2, newNode(2, newNode(2, newNode(2, NULL)))));
    struct ListNode *l2 = deleteDuplicates(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");
}
