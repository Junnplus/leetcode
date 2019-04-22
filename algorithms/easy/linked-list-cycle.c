#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool hasCycle(struct ListNode *head) {
    struct ListNode *pre, *cur;
    if (head == NULL)
        return false;
    pre = head, cur = head->next;
    while (cur !=NULL && cur->next != NULL && cur->next->next != NULL) {
        if (pre == cur) {
            return true;
        }
        pre = pre->next;
        cur = cur->next->next;
    }
    return false;
}

int main() {
    struct ListNode *l1, *cy, *tail;
    tail = newNode(5, NULL);
    cy = newNode(2, newNode(3, newNode(4, tail)));
    tail->next = cy;
    l1 = newNode(3, cy);
    printf("%d", hasCycle(l1) == true);

    l1 = newNode(3, newNode(2, newNode(3, newNode(4, NULL))));
    printf("%d", hasCycle(l1) == false);

    tail = newNode(2, NULL);
    l1 = newNode(1, tail);
    tail->next = l1;
    printf("%d", hasCycle(l1) == true);

    l1 = newNode(1, NULL);
    printf("%d", hasCycle(l1) == false);
}
