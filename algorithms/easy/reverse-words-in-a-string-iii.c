#include <stdio.h>
#include <string.h>

void reverseString(char *s, int start, int end) {
    while (start < end) {
        char tmp = s[start];
        s[start]= s[end];
        s[end] = tmp;
        start ++;
        end --;
    }
}

char * reverseWords(char * s){
    int p=0,q;
    int l = strlen(s);
    for (int i=0; i<=l; i++) {
        if (s[i] == ' ') {
            q = i-1;
            reverseString(s, p, q);
            p = i+1;
        }
        if (i == strlen(s)) {
            reverseString(s, p, l - 1);
        }
    }
    //reverseString(s, 0, strlen(s) - 1);
    return s;
}

int main() {
    char s[30] = "Let's take LeetCode contest";
    reverseWords(s);
    printf("%s\n", s);
}
