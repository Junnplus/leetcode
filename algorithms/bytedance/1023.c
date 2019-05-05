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

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL)
        return NULL;
    struct ListNode *pre, *cur;
    pre = head;
    cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (pre == cur->next) {
            pre = head;
            while (pre != cur) {
                pre = pre->next;
                cur = cur->next;
            }
            return pre;
        }
        pre = pre->next;
        cur = cur->next->next;
    }
    return NULL;
}
