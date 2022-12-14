#include <stdio.h>

int
map(char c)
{
    switch (c) {
    // case 'I': return 1;
    case 'V':
        return 5;
    // case 'X': return 10;
    case 'L':
        return 50;
    // case 'C': return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int
romanToInt(char *s)
{
    int ret = 0;
    while (*s != '\0') {
        printf("%c, %d\n", s[0], ret);
        if (s[0] == 'I') {
            if (s[1] == 'V') {
                ret += 4;
                s++;
            } else if (s[1] == 'X') {
                ret += 9;
                s++;
            } else
                ret += 1;
            s++;
        } else if (s[0] == 'X') {
            if (s[1] == 'L') {
                ret += 40;
                s++;
            } else if (s[1] == 'C') {
                ret += 90;
                s++;
            } else
                ret += 10;
            s++;
        } else if (s[0] == 'C') {
            if (s[1] == 'D') {
                ret += 400;
                s++;
            } else if (s[1] == 'M') {
                ret += 900;
                s++;
            } else
                ret += 100;
            s++;
        } else {
            ret += map(s[0]);
            s++;
        }
    }
    return ret;
}

int
main()
{
    static int map[] = {500, 0, 0, 0, 0, 0, 0, 0, 50, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 5};
    for (int i = 0; i < sizeof(map); i++) {
        printf("%d:%d\n", i + 68, map[i]);
    }
    printf("%d, %d, %d, %d\n", map['V' - 68], map['L' - 68], map['D' - 68], map['M' - 68]);
}
