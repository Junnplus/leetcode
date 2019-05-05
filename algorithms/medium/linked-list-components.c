#include <stdio.h>
#include <stdlib.h>

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

int numComponents(struct ListNode* head, int* G, int GSize) {
    int N[10000] = {0};
    for (int i=0;i<GSize;i++) {
        N[*G++] = 1;
    }
    int flag = 0, val, count = 0;
    while (head != NULL) {
        val = head->val;
        if (N[val] == 1 && flag == 0){
            count += 1;
            flag = 1;
        }
        if (N[val] == 0) {
            flag = 0;
        }
        head = head->next;
    }
    return count;
}

int main() {
    struct ListNode *l1;
    int G[] = {0, 3, 1, 4};
    l1 = newNode(0, newNode(1, newNode(2, newNode(3, newNode(4, NULL)))));
    printf("%d\n", numComponents(l1, G, 4));

    int G1[] = {0, 3, 1};
    l1 = newNode(0, newNode(1, newNode(2, newNode(3, NULL))));
    printf("%d\n", numComponents(l1, G1, 4));
}
