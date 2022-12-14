#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ret = malloc(sizeof(struct ListNode));
    struct ListNode *n1 = l1, *n2 = l2, *result = ret;

    int carry = 0;
    while (1) {
        if (n1 == NULL && n2 == NULL) break;
        if (n1 == NULL) {
            result->val = (carry + n2->val) % 10;
            carry = (carry + n2->val) / 10;
            n2 = n2->next;
        } else if (n2 == NULL) {
            result->val = (carry + n1->val) % 10;
            carry = (carry + n1->val) / 10;
            n1 = n1->next;
        } else {
            result->val = (carry + (n1->val + n2->val)) % 10;
            carry = (carry + n1->val + n2->val) / 10;
            n1 = n1->next;
            n2 = n2->next;
        }
        if (n1 != NULL || n2 != NULL) {
            result->next = malloc(sizeof(struct ListNode));
            result = result->next;
        }
        // n1 = n1->next;
        // n2 = n2->next;
    }
    return ret;
}

int main() {
    struct ListNode* n1 = malloc(sizeof(struct ListNode));
    n1->next = malloc(sizeof(struct ListNode));
    n1->next->next = malloc(sizeof(struct ListNode));
    n1->next->next->next = malloc(sizeof(struct ListNode));
    n1->val = 2;
    n1->next->val = 4;
    n1->next->next->val = 3;
    n1->next->next->next->val = 2;

    struct ListNode* n2 = malloc(sizeof(struct ListNode));
    n2->next = malloc(sizeof(struct ListNode));
    n2->next->next = malloc(sizeof(struct ListNode));
    n2->val = 5;
    n2->next->val = 6;
    n2->next->next->val = 4;

    struct ListNode* res = addTwoNumbers(n1, n2);
    printf("%d, %d, %d, %d\n", res->val, res->next->val, res->next->next->val,
           res->next->next->next->val);
}
