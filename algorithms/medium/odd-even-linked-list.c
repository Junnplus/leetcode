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

struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *pre, *cur, *tail, *tailx, *tmp;
    if (head == NULL || head->next == NULL)
        return head;
    tail = head;
    int flag = 0, c = 0;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tailx = tail;
    pre = head;
    cur = head->next;
    while (cur != NULL) {
        if (flag == 1) {
            break;
        }
        if (cur == tail) {
            flag = 1;
        }
        if (++c % 2 != 0 && cur->next != NULL) {
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
    return head;    
}

int main() {
    struct ListNode *head;
    head = newNode(1, newNode(2, newNode(3, newNode(4, newNode(5, newNode(6, NULL))))));
    head = oddEvenList(head);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
    head = newNode(1, newNode(2, NULL));
    head = oddEvenList(head);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
