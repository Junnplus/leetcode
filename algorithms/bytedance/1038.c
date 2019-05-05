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

void _reverseList(struct ListNode* head, struct ListNode **pre){
    struct ListNode *tmp;
    if (head == NULL)
        return;
    tmp = head->next;
    head->next = *pre;
    *pre = head;
    _reverseList(tmp, pre);
}

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL ||head->next == NULL)
        return head;
    struct ListNode *pre = NULL;
    _reverseList(head, &pre);
    return pre;
}

int main() {
    head = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    head = reverseList(head);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}
