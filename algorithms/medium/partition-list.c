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

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *pre, *cur, *tail, *tailx, *tmp;
    if (head == NULL || head->next == NULL)
        return head;
    tail = head;
    int flag = 0;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tailx = tail;
    struct ListNode *node = newNode(-1, head);
    pre = node;
    cur = node->next;
    while (cur != NULL) {
        if (flag == 1) {
            break;
        }
        if (cur == tail) {
            flag = 1;
        }
        if (cur->val>=x && cur->next!=NULL) {
            pre->next = cur->next;
            tmp = cur->next;
            cur->next = NULL;
            tailx->next = cur;
            cur = pre->next;
            tailx = tailx->next;
        } else {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return node->next;    
}

int main() {
    struct ListNode *head;
    head = newNode(1, newNode(4, newNode(3, newNode(2, newNode(5, newNode(2, NULL))))));
    head = partition(head, 3);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    head = newNode(4, newNode(4, newNode(3, newNode(2, newNode(5, newNode(2, NULL))))));
    head = partition(head, 3);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    head = newNode(1, newNode(2, NULL));
    head = partition(head, 0);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    head = newNode(1, newNode(2, NULL));
    head = partition(head, 2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    head = newNode(1, newNode(2, NULL));
    head = partition(head, 3);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
