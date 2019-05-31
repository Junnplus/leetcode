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
    struct ListNode *cur = head, *tmp;
    int len = 1;
    if (head == NULL || head->next == NULL)
        return head;
    while (cur->next != NULL) {
        len++;
        cur = cur->next;
    }
    k = k % len;
    if (k == 0)
        return head;
    k = len - k -1;
    cur->next = head;
    cur = head;
    while (k-- > 0) {
        cur = cur->next;
    }
    tmp = cur->next;
    cur->next = NULL;
    return tmp;
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
