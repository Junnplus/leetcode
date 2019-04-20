#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newListNode(int val, struct ListNode* next) {
    struct ListNode* node = malloc(sizeof node);
    node->val = val;
    node->next = next;
    return node;
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    struct ListNode* l3 = NULL;
    struct ListNode* head = NULL;
    int f = 0;
    int val = 0;
    while(l1 != NULL && l2 != NULL) {
        val = l1->val + l2->val + f;
        f = val / 10;
        if(head == NULL) {
            head = malloc(sizeof *head);
            head->val = val % 10;
            head->next = NULL;
            l3 = head;
        } else {
            struct ListNode* node = malloc(sizeof (struct ListNode));
            node->val = val % 10;
            node->next = NULL;
            head->next = node;
            head = head->next; 
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL) {
        val = l1->val + f;
        f = val / 10;
        struct ListNode* node = malloc(sizeof (struct ListNode));
        node->val = val % 10;
        node->next = NULL;
        head->next = node;
        head = head->next;
        l1 = l1->next;
    }
    while(l2 != NULL) {
        val = l2->val + f;
        f = val / 10;
        struct ListNode* node = malloc(sizeof (struct ListNode));
        node->val = val % 10;
        node->next = NULL;
        head->next = node;
        head = head->next;
        l2 = l2->next;
    }
    if(f != 0) {
        struct ListNode* node = malloc(sizeof (struct ListNode));
        node->val = f;
        node->next = NULL;
        head->next = node;
        head = head->next;
    }
    return l3;
}

int main() {
    struct ListNode* l1 = newListNode(2, newListNode(4, newListNode(3, NULL)));
    struct ListNode* l2 = newListNode(5, newListNode(6, newListNode(8, newListNode(9, NULL))));
    struct ListNode* l3 = addTwoNumbers(l1, l2);
    while(l3 != NULL) {
        printf("%d ", l3->val);
        l3 = l3->next;
    }
}
