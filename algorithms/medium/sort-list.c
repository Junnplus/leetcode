#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(int val, struct ListNode *next) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = next;
    return node;
}

struct ListNode *getPartion(struct ListNode *begin, struct ListNode *end) {
    int value = begin->val, tmp;
    struct ListNode *p = begin;
    struct ListNode *q = begin->next;
    while (q != end) {
        if (q->val < value) {
            p = p->next;
            tmp = q->val;
            q->val = p->val;
            p->val = tmp;
        }
        q = q->next;
    }
    begin->val = p->val;
    p->val = value;
    return p;
}

void Qsort(struct ListNode *start, struct ListNode *end) {
    if (start != end) {
        struct ListNode *index = getPartion(start, end);
        Qsort(start, index);
        Qsort(index->next, end);
    }
}

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *start = head;
    struct ListNode *end = NULL;
    Qsort(start, end);
    return head;
}


int main() {
    struct ListNode *head = newNode(4, newNode(2, newNode(5, newNode(3, newNode(7, newNode(9, newNode(0, newNode(1, NULL))))))));
    struct ListNode *node = sortList(head);
    struct ListNode *cur = node;
    while (cur != NULL) {
        printf("%d\n", cur->val);
        cur = cur->next;
    }
}
