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

struct ListNode *node;
bool forPalindromeLinked(struct ListNode* head) {
    if (head != NULL) {
        bool value = forPalindromeLinked(head->next);
        if (value == false)
            return false;
        if (head->val != node->val) {
            return false;
        }
        node = node->next;
    }
    return true;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL)
        return false;
    struct ListNode *pre, *cur;
    pre = cur = head;
    while (cur->next != NULL && cur->next->next != NULL) {
        pre = pre->next;
        cur = cur->next->next;
    }
    pre = pre->next;
    node = head;
    return forPalindromeLinked(pre);
}

int main() {
    struct ListNode *l1;
    l1 = newNode(1, newNode(2, newNode(4, newNode(2, newNode(1, NULL)))));
    printf("%d\n", isPalindrome(l1) == true);

    l1 = newNode(1, newNode(2, newNode(2, newNode(1, NULL))));
    printf("%d\n", isPalindrome(l1) == true);

    l1 = newNode(1, newNode(3, newNode(2, newNode(1, NULL))));
    printf("%d\n", isPalindrome(l1) == true);

    l1 = newNode(1, newNode(1, NULL));
    printf("%d\n", isPalindrome(l1) == true);

    l1 = newNode(1, newNode(2, NULL));
    printf("%d\n", isPalindrome(l1) == true);

    l1 = newNode(1, NULL);
    printf("%d\n", isPalindrome(l1) == true);
}
