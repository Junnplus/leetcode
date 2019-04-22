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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = 0, len2 = 0, diff = 0;
    struct ListNode *c1, *c2, *cur, *pre, *tmp;
    c1 = l1;
    c2 = l2;
    while (c1 != NULL) {
        len1 += 1;
        c1 = c1->next;
    }
    while (c2 != NULL) {
        len2 += 1;
        c2 = c2->next;
    }

    struct ListNode *head = NULL, *node;
    if (len1 > len2) {
        cur = l1;
        diff = len1 - len2;
        while (diff > 0) {
            diff --;
            node = newNode(cur->val, head);
            head = node;
            cur = cur->next;
        }
        c1 = cur;
        c2 = l2;
    } else {
        cur = l2;
        diff = len2 - len1;
        while (diff > 0) {
            diff --;
            node = newNode(cur->val, head);
            head = node;
            cur = cur->next;
        }
        c2 = cur;
        c1 = l1;
    }
    while (c1 != NULL && c2 != NULL) {
        node = newNode(c1->val + c2->val, head);
        head = node;
        c1 = c1->next;
        c2 = c2->next;
    }

    cur = head->next;
    pre = head;
    pre->next = NULL;
    int flag = head->val / 10, val;
    head->val %= 10;

    while (cur != NULL) {
        val = cur->val + flag;
        flag = val / 10;
        cur->val = val % 10;
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head = pre;
    if (flag != 0) {
        head = newNode(flag, head);
    }
    return head;
}

int main() {
    struct ListNode *head, *l1, *l2;
    l1 = newNode(7, newNode(2, newNode(4, newNode(3, NULL))));
    l2 = newNode(5, newNode(6, newNode(4, NULL)));
    head = addTwoNumbers(l1, l2);
    while (head != NULL) {
        printf("%d\n", head->val);
        head = head->next;
    }
    printf("\n");

    l1 = newNode(5, NULL);
    l2 = newNode(5, NULL);
    head = addTwoNumbers(l1, l2);
    while (head != NULL) {
        printf("%d\n", head->val);
        head = head->next;
    }
}
