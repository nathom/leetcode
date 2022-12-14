#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
isMatch(char *s, char *p)
{
    s = "aasdfasdfasdfasdfas";
    p = "aasdf.*asdf.*asdf.*asdf.*s";
    // s = "aa";
    // p = "a*";
    // s = "mississippi";
    // p = "mis*is*p*.";
    const char *s_start = s;
    const char *p_start = p;

    // start/end of backtrackable range, or NULL
    // if no backtrack available
    char *bt_start = NULL, *bt_end = NULL;
    // pattern char after backtracked pattern char, or NULL
    char *bt_pat = NULL;
    bool fail = false;  // reached end of string
    for (;;) {          // TODO: change to while
        printf("s: %c, p: %c, fail %d, bt: (%c-%c)\n", *s, *p, fail,
               bt_start != NULL ? *bt_start : 'x', bt_end != NULL ? *bt_end : 'x');
        if (*p == '\0' && *s != '\0') {
            printf("pattern done, setting fail=true\n");
            fail = true;
        }
        if (fail) {
            if (!(bt_end != NULL && bt_start != NULL && bt_end - bt_start > 0)) return false;
            printf("backtracking...\n");
            if (bt_end - bt_start > 0) {
                printf("bt_end: %s\n", bt_end);
                bt_end--;
                s = bt_end;
                p = bt_pat;
                printf("move s to '%s' p to '%s'\n", s, p);
                fail = false;
            }
        } else if (*s == '\0' && *p == '\0') {
            // !fail and reached end of string
            return true;
        }
        /*if (*p == '\0' && !has_bt) {
            return false;
        }*/
        printf("start iter:: s: %c, p: %c, fail %d, bt: (%p-%p)\n", *s, *p, fail, bt_start, bt_end);
        if (*p == '.') {
            if (*s == '\0') {
                fail = true;
                continue;
            }
            if (p[1] == '*') {  // .*
                // move to end of s and set bt range
                bool matched = false;
                char *start = s;
                while (*s != '\0') {
                    matched = true;
                    s++;
                }
                bt_end = s;
                if (matched) {
                    bt_pat = p + 2;
                    bt_start = start;
                    bt_end = s;
                }
                p += 2;
                continue;
            } else {  // .
                // s has chars left, so we can move ahead
                p++;
                s++;
                continue;
            }
        } else {
            // *p is alnum
            if (p[1] == '*') {  // x*
                bool matched = false;
                char *start = s;
                while (*s == *p) {
                    matched = true;
                    s++;
                }
                if (matched) {
                    bt_pat = p + 2;
                    bt_start = start;
                    bt_end = s;
                }
                p += 2;
                continue;
            } else {  // x
                if (*s == '\0') {
                    fail = true;
                } else if (*p == *s) {
                    s++;
                    p++;
                } else {
                    fail = true;
                }
                continue;
            }
        }
    }
}

int
main()
{
    printf("result: %d\n", isMatch("mississippi", "mis*is*p*."));
}
