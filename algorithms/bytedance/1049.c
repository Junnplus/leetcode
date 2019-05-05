#include <stdio.h>
#include <stdlib.h>
#define STACKLEN 10000


typedef struct {
    int top;   
    int value[STACKLEN];
    int min[STACKLEN];
} MinStack;

int min(int a, int b) {
    return a > b? b : a;
}

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    obj->value[obj->top + 1] = x;
    if (obj->top == -1) {
        obj->min[obj->top+1] = x;
    } else {
        obj->min[obj->top+1] = min(obj->min[obj->top], x);
    }
    obj->top ++;
}

void minStackPop(MinStack* obj) {
    obj->top --;
}

int minStackTop(MinStack* obj) {
    return obj->value[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

int main() {
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    int p1 = minStackGetMin(obj);
    printf("%d\n", p1);
    minStackPop(obj);
    int p2 = minStackTop(obj);
    printf("%d\n", p2);
    int p3 = minStackGetMin(obj);
    printf("%d\n", p3);

    minStackFree(obj);
}
