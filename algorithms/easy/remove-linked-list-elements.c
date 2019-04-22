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

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    if (head == NULL)
        return NULL;
    struct ListNode *cur = head;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

int main() {
    struct ListNode *l1 = newNode(1, newNode(2, newNode(2, newNode(4, newNode(5, NULL)))));
    struct ListNode *l2 = removeElements(l1, 2);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(1, newNode(1, newNode(4, newNode(5, NULL)))));
    l2 = removeElements(l1, 1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(1, newNode(1, newNode(1, newNode(1, NULL)))));
    l2 = removeElements(l1, 1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");

    l1 = newNode(1, newNode(1, newNode(1, newNode(1, newNode(1, NULL)))));
    l2 = removeElements(NULL, 1);
    while(l2 != NULL) {
        printf("%d ", l2->val);
        l2 = l2->next;
    }
    printf("\n");
}
