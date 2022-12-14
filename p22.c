#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void
printBits(size_t const size, void const *const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}
bool
is_well_formed(unsigned int p, const int n)
{
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += (p & (1 << i)) == 0 ? -1 : 1;
        if (sum > 0)  // because were moving in reverse
            return false;
    }
    return sum == 0;
}
char **
generateParenthesis(int n, int *returnSize)
{
    // 1 : ["()"] -> [(10)]
    // 2: ["(())", "()()"] -> [(1100), (1010)]
    // 3: ["((()))","(()())","(())()","()(())","()()()"]
    // -> [111000, 110100, 110010, 101100, 101010]
    // 110001 (()))(
    // printf("%d, %d\n", is_well_formed(0b110001, n), is_well_formed(0b111000, n));
    /*
    for (int i = 1; i <= 8; i++) {
        int cnt = 0;
        for (unsigned int j = 0; j < 1<<(2*i); j++) {
            if (is_well_formed(j, i)) cnt++;
        }
        printf("i: %d, 2^i: %d, well_formed: %d\n", i, 1<<(2*i), cnt);
    }
    */

    /*
    int cnt = 0;
    for (unsigned int j = 0; j < 1<<(2*3); j++) {
        if (is_well_formed(j, 3)) {
            printBits(1, &j);
            cnt++;
        }

    }
    */

    // printf("i: %d, 2^i: %d, well_formed: %d\n", i, 1<<(2*i), cnt);

    static size_t nsize[] = {1, 2, 5, 14, 42, 132, 429, 1430};

    for (int n = 1; n <= 8; n++) {
        char **ret = calloc(nsize[n - 1], sizeof(char *));
        *returnSize = nsize[n - 1];
        char **r = ret;
        char *block = calloc((2 * n + 1) * nsize[n - 1], sizeof(char));
        printf("static char n%d[] = \"", n);
        for (unsigned int i = 0; i < 1 << (2 * n); i++) {
            if (is_well_formed(i, n)) {
                // printBits(1, &i);
                *r++ = block;
                for (int j = 0; j < 2 * n; j++) {
                    *block++ = (i & (1 << j)) ? ')' : '(';
                    // printf("added %c\n", block[-1]);
                }
                *block++ = '\0';
                printf("%s\\0", r[-1]);
            }
        }
        printf("\";\n");
        // return ret;
    }
    return NULL;
}

int
main()
{
    int n = 0;
    generateParenthesis(3, &n);
}
