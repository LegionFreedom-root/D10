#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

int test_push(void);
int test_pop(void);

int main() {
    int result = 0;
    result += test_push();
    result += test_pop();
    if (result == 0) {
        printf("All tests: SUCCESS");
        return SUCCESS;
    }
    printf("Tests failed: FAIL");
    return FAIL;
}

int test_push(void) {
    int res = SUCCESS;
    struct stack *st = init();
    if (st == NULL) return FAIL;
    if (push(st, 10) != 0) res = FAIL;
    if (push(st, 20) != 0) res = FAIL;
    if (push(st, 30) != 0) res = FAIL;
    if (st->size != 3) res = FAIL;
    if (st->top == NULL || st->top->value != 30) res = FAIL;
    destroy(st);
    printf("test_push: %s", res == SUCCESS ? "SUCCESS" : "FAIL");
    return res;
}

int test_pop(void) {
    int res = SUCCESS;
    int value = 0;
    struct stack *st = init();
    if (st == NULL) return FAIL;
    // pop from empty stack
    if (pop(st, &value) == 0) res = FAIL;
    push(st, 10);
    push(st, 20);
    push(st, 30);
    // LIFO order: 30, 20, 10
    if (pop(st, &value) != 0 || value != 30) res = FAIL;
    if (pop(st, &value) != 0 || value != 20) res = FAIL;
    if (pop(st, &value) != 0 || value != 10) res = FAIL;
    if (st->size != 0) res = FAIL;
    if (pop(st, &value) == 0) res = FAIL;
    destroy(st);
    printf("test_pop: %s", res == SUCCESS ? "SUCCESS" : "FAIL");
    return res;
}
