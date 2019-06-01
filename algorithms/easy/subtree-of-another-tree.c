#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode *s, struct TreeNode *t) {
    if (s == NULL && t == NULL)
        return true;
    if ((s != NULL && t == NULL) || (s == NULL && t != NULL) || (s->val != t->val))
        return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (s == NULL || t == NULL)
        return false;
    bool r = false;
    if (s->val == t->val) {
        r = isSameTree(s, t);
    }
    return r || isSubtree(s->left, t) || isSubtree(s->right, t);
}
