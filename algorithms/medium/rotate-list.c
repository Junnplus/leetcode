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

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *cur;
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    cur = head;
    int len = 1;
    while (cur->next != NULL) {
        cur = cur->next;
        len++;
    }
    if (k == len) {
        return head;
    }
    cur->next = head;
    k = len - k % len;

    cur = head;
    while (--k > 0) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next=NULL;
    return head;
}

int main() {
    struct ListNode *head;
    head = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    head = rotateRight(head, 2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    head = newNode(0, newNode(1, newNode(2, NULL)));
    head = rotateRight(head, 4);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
