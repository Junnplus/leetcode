#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *head;

struct ListNode* newNode(int val, struct ListNode *next) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = next;
    return node;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *head, *pre;

    if (l1->val > l2->val) {
        head = l2;
        l2 = l2->next;
    } else {
        head = l1;
        l1 = l1->next;
    }
    pre = head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val > l2->val) {
            pre->next = l2;
            l2 = l2->next;
        } else {
            pre->next = l1;
            l1 = l1->next;
        }
        pre = pre->next;
    }
    if (l1 != NULL) {
        pre->next = l1;
    }
    if (l2 != NULL) {
        pre->next = l2;
    }
    return head;
}

int main() {
    printf("1\n");
    struct ListNode *l1, *l2;
    l1 = newNode(1, newNode(2, newNode(4, newNode(5, NULL))));
    l2 = newNode(1, newNode(3, newNode(4, NULL)));
    head = mergeTwoLists(l1, l2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n2");

    l1 = newNode(1, newNode(2, newNode(4, newNode(5, NULL))));
    l2 = newNode(2, NULL);
    head = mergeTwoLists(l1, l2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}
