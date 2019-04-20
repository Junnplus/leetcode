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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    struct ListNode *head = NULL;
    struct ListNode *cur = head;
    struct ListNode *node;
    while (l1 != NULL && l2 != NULL) {
        int val;
        if (l1->val > l2->val) {
            val = l2->val;
            l2 = l2->next;
        } else {
            val = l1->val;
            l1 = l1->next;
        }
        node = newNode(val, NULL);
        if (head == NULL)
            head = cur = node;
        else {
            cur->next = node;
            cur = cur->next;
        }
    }
    while (l1 != NULL) {
        node = newNode(l1->val, NULL);
        cur->next = node;
        cur = cur->next;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        node = newNode(l2->val, NULL);
        cur->next = node;
        cur = cur->next;
        l2 = l2->next;
    }
    return head;
}


int main() {
    struct ListNode *l1 = newNode(1, newNode(2, newNode(4, NULL)));
    struct ListNode *l2 = newNode(1, newNode(3, newNode(4, NULL)));
    struct ListNode *l3 = mergeTwoLists(l1, l2);
    while(l3 != NULL) {
        printf("%d ", l3->val);
        l3 = l3->next;
    }
    printf("\n");
}
