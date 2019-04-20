#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    int i = 0, j = 0, max = 0;
    int count = 0;
    int alphabet[95] = {0};
    while (i < len && j < len) {
        if (alphabet[s[j] - ' '] == 0) {
            alphabet[s[j++] - ' '] ++;
            count ++;
            if (max < count) {
                max = count;
            }
        } else {
            if (-- alphabet[s[i++] - ' '] == 0) {
                count --;
            }
        }
    }
    return max;
}

int main() {
    char *s = "pwwkew";
    printf("%s %d\n", s, lengthOfLongestSubstring(s));

    char *s1 = "bbbbb";
    printf("%s %d\n", s1, lengthOfLongestSubstring(s1));

    char *s2 = "abcabcbb";
    printf("%s %d\n", s2, lengthOfLongestSubstring(s2));

    char *s3 = "";
    printf("%s %d\n", s3, lengthOfLongestSubstring(s3));
}
