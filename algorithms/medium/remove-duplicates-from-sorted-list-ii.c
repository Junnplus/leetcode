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

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode *node, *pre, *cur, *curx;
    node = newNode(-1, head);
    pre = node;
    cur = head;
    while (cur != NULL) {
        curx = cur->next;
        while (curx != NULL && curx->val == cur->val) {
            curx = curx->next;
        }
        if (curx != cur->next) {
            cur = curx;
            pre->next = cur;
        } else {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return node->next;
}

int main() {
    struct ListNode *head;
    head = newNode(1, newNode(2, newNode(3, newNode(3, newNode(4, newNode(4, newNode(5, NULL)))))));
    head = deleteDuplicates(head);
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    head = newNode(1, newNode(2, NULL));
    head = deleteDuplicates(head);
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    head = newNode(1, newNode(1, NULL));
    head = deleteDuplicates(head);
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    head = newNode(1, newNode(1, newNode(1, NULL)));
    head = deleteDuplicates(head);
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    head = newNode(2, newNode(2, newNode(1, NULL)));
    head = deleteDuplicates(head);
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
