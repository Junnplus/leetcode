#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode *head;
    int len;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList *linked = malloc(sizeof(MyLinkedList));
    linked->head = NULL;
    linked->len = 0;
    return linked;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    struct ListNode *head = obj->head;
    int i = 0;
    if (index <0 || index > obj->len)
        return -1;
    while (head != NULL) {
        if (i++ == index)
            return head->val;
        head = head->next;
    }
    return -1;
}


/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode *head = obj->head;
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = head;
    obj->head = node;
    obj->len ++;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode *head = obj->head;
    if (head == NULL)
        myLinkedListAddAtHead(obj, val);

    while (head->next != NULL)
        head = head->next;
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    head->next = node;
    obj->len ++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->len)
        return;
    if (index <= 0)
        return myLinkedListAddAtHead(obj, val);
    if (index == obj->len)
        return myLinkedListAddAtTail(obj, val);
    struct ListNode *head = obj->head;
    int l = 1;
    struct ListNode *pre = head;
    head = head->next;
    while (head->next != NULL) {
        if (l++ == index)
            break;
        head = head->next;
        pre = pre->next;
    }
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = pre->next;
    pre->next = node;
    obj->len ++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->len)
        return;

    struct ListNode *head = obj->head;
    if (head == NULL)
        return;
    if (index == 0) {
        obj->head = obj->head->next;
        obj->len --;
        return;
    }
    int l = 1;
    struct ListNode *pre = head;
    head = head->next;
    while (head->next != NULL) {
        if (l++ == index)
            break;
        head = head->next;
        pre = pre->next;
    }
    pre->next = head->next;
    obj->len --;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *head = obj->head;
    struct ListNode *tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    obj->head = NULL;
    obj->len = 0;
}
