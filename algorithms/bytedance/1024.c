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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0, diff;
    if (headA == NULL || headB == NULL)
        return NULL;
    struct ListNode *curA, *curB;
    curA = headA;
    curB = headB;
    while (curA != NULL) {
        lenA ++;
        curA = curA->next;
    }
    while (curB != NULL) {
        lenB ++;
        curB = curB->next;
    }
    curA = headA;
    curB = headB;
    if (lenA > lenB) {
        diff = lenA- lenB;
        while (diff-- > 0) {
            curA = curA->next;
        }
    } else if (lenA < lenB) {
        diff = lenB- lenA;
        while (diff-- > 0) {
            curB = curB->next;
        }
    }
    while (curA != NULL) {
        if (curA == curB)
            return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}
