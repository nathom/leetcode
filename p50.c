#include <stdint.h>
#include <stdio.h>

double myPow(double x, int n);
int
main()
{
    printf("%f\n", myPow(2, 10));
}

double
myPow(double x, int n)
{
    double ret = 1.0;
    uint64_t p = n < 0 ? -((int64_t)n) : n;
    // ret = rep_square(x, 0) * (p& != 0)
    double y = x;
    unsigned int s = 1;

    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;

    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;
    if (p & s) {
        ret *= y;
    }
    y *= y;
    s <<= 1;

    // for (unsigned int i = 0, s = 1; i < 32; i++, s <<= 1) {
    //     if (p&s) {
    //         ret *= y;
    //     }
    //     y *= y;
    // }
    return n < 0 ? 1.0 / ret : ret;
}
