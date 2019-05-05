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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL, *node, *cur;
    int val, f=0;
    while (l1 != NULL && l2 != NULL) {
        val = l1->val + l2->val + f;
        f = val / 10;
        node = newNode(val % 10, NULL);
        if (head == NULL) {
            head = node;
            cur = head;
        } else {
            cur->next = node;
            cur = cur->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        val = l1->val + f;
        f = val / 10;
        cur->next = newNode(val % 10, NULL);
        cur = cur->next;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        val = l2->val + f;
        f = val / 10;
        cur->next = newNode(val % 10, NULL);
        cur = cur->next;
        l2 = l2->next;
    }
    if (f != 0) {
        cur->next = newNode(f, NULL);
    }
    return head;
}

int main() {
    struct ListNode *l1, *l2;
    l1 = newNode(2, newNode(4, newNode(3, NULL)));
    l2 = newNode(5, newNode(6, newNode(4, NULL)));
    head = addTwoNumbers(l1, l2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    l1 = newNode(5, newNode(4, newNode(3, NULL)));
    l2 = newNode(5, NULL);
    head = addTwoNumbers(l1, l2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}
