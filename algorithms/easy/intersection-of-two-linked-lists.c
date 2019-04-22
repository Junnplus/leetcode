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

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0, diff;
    struct ListNode *cur, *curA, *curB;
    cur = headA;
    while (cur != NULL) {
        lenA += 1;
        cur = cur->next;
    }
    cur = headB;
    while (cur != NULL) {
        lenB += 1;
        cur = cur->next;
    }
    curA = headA;
    curB = headB;
    if (lenA > lenB) {
        diff = lenA - lenB;
        while (diff-- > 0) {
            curA = curA->next;
        }
    } else {
        diff = lenB - lenA;
        while (diff-- > 0) {
            curB = curB->next;
        }
    }
    while (curA != NULL & curB != NULL) {
        if (curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}


int main() {
    struct ListNode *in = newNode(8 ,newNode(4, newNode(5, NULL)));
    struct ListNode *l1 = newNode(4, newNode(1, in));
    struct ListNode *l2 = newNode(5, newNode(0, newNode(1, in)));
    struct ListNode *out = getIntersectionNode(l1, l2);
    if (in == out) {
        printf("yes\n");
    }

    in = NULL;
    l1 = newNode(2, newNode(6, newNode(4, NULL)));
    l2 = newNode(1, newNode(5, NULL));
    out = getIntersectionNode(l1, l2);
    if (in == out) {
        printf("yes\n");
    }

    in = NULL;
    l1 = newNode(2, newNode(6, newNode(4, NULL)));
    l2 = NULL;
    out = getIntersectionNode(l1, l2);
    if (in == out) {
        printf("yes\n");
    }

    in = newNode(2, newNode(4, NULL));
    l1 = newNode(0, newNode(9, newNode(1, in)));
    l2 = newNode(3, in);
    out = getIntersectionNode(l1, l2);
    if (in == out) {
        printf("yes\n");
    }
}
