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

void deleteNode(struct ListNode* node) {
    if (node == NULL)
        return;
    node->val = node->next->val;
    node->next = node->next->next;
}

int main() {
    head = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, NULL)))));
    deleteNode(head);
    printf("\n");
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    struct ListNode *a = newNode(2, newNode(3, newNode(2, newNode(5, NULL))));
    head = newNode(1, a);
    deleteNode(a);
    printf("\n");
    while(head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
