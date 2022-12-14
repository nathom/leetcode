#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char* s, int start, int end);
char* longestPalindrome(char* s);

char* longestPalindrome(char* s) {
    // inclusive indices of substring
    int maxStart = 0, maxEnd = 0;
    int len = strlen(s);
    for (int end = 0; end < len; end++) {
        for (int start = 0; start < end; start++) {
            if (isPalindrome(s, start, end) &&
                (end - start) > (maxEnd - maxStart)) {
                maxEnd = end;
                maxStart = start;
            }
        }
    }
    char* ret = malloc(sizeof(char) * (maxEnd - maxStart + 1));
    strncpy(ret, s + maxStart, maxEnd - maxStart + 1);
    return ret;
}

int isPalindrome(char* s, int start, int end) {
    int i = start, j = end;
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
