// #include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int indexOf(int* nums, int start, int end, int target);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ret = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int lookFor = target - nums[i];
        int idx = indexOf(nums, i + 1, numsSize, lookFor);
        if (idx != -1) {
            ret[0] = i;
            ret[1] = idx;
            return ret;
        }
    }
    return NULL;
    // assert(0);
}

int indexOf(int* nums, int start, int end, int target) {
    for (int i = start; i < end; i++) {
        if (nums[i] == target) return i;
    }
    return -1;
}

int main() {
    // test 1
    int nums[] = {3, 2, 4};
    int target = 6;
    int retSize = -1;
    int* ret = twoSum(nums, 3, target, &retSize);
    printf("[%d %d]\n", ret[0], ret[1]);
}
