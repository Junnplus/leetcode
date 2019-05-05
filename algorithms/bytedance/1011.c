#include <stdio.h>
#include <string.h>

void reverseWord(char **s, int len) {
    char *c = *s, t;
    int i, j;
    i = 0, j = len - 1;
    while (i <= j) {
        t = *(c+i);
        *(c+i) = *(c+j);
        *(c+j) = t;
        i ++;
        j --;
    }
}

char * reverseWords(char * s){
    int f = 0, i;
    char *e = s, *h = s;
    while (*s == ' ' && *s != 0) {
        s++;
    }
    h = s;
    if (*s == 0)
        return s;
    while (*s != 0) s++;

    while (*s == ' ' || *s == 0) {
        s--;
    }
    *(s+1) = 0;
    s = h;

    e = s;
    while (*s != 0) {
        if (f == 1) {
            while (*s == ' ' && *s != 0) {
                s++;
            }
            f = 0;
        }
        if (*s == ' ') {
            f = 1;
        }
        if (e != s) {
            *e = *s;
        }
        s ++;
        e ++;
    }
    *e = 0;
    s = h;
    reverseWord(&s, strlen(s));
    f = 0;
    for (i = 0; i < strlen(s); i ++) {
        f ++;
        if (*(s +i +1) == ' ' || *(s+i+1) == 0) {
            char *t = s + (++i) -f;
            reverseWord(&t, f);
            f = 0;
        }
    }
    return s;
}

int main() {
    char s[] = "  hello world!  ";
    // "as cba"
    printf("%s\\0", reverseWords(s));
}
