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

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *pre = head, *cur = head;
    while (cur->next != NULL && cur->next->next != NULL) {
        pre = pre->next;
        cur = cur->next->next;
    }
    if (cur->next != NULL)
        pre = pre->next;
    return pre;
}

int main() {
    struct ListNode *l1, *l2;
    l1 = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    l2 = middleNode(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, newNode(6, NULL))))));
    l2 = middleNode(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(2, NULL));
    l2 = middleNode(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(2, newNode(3, NULL)));
    l2 = middleNode(l1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");
}
