#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *init(void) {
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    if (st == NULL) return NULL;
    st->top = NULL;
    st->size = 0;
    return st;
}

int push(struct stack *stack, int value) {
    if (stack == NULL) return -1;
    struct stack_node *node = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (node == NULL) return -1;
    node->value = value;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    return 0;
}

int pop(struct stack *stack, int *value) {
    if (stack == NULL || stack->top == NULL || value == NULL) return -1;
    struct stack_node *node = stack->top;
    *value = node->value;
    stack->top = node->next;
    free(node);
    stack->size--;
    return 0;
}

void destroy(struct stack *stack) {
    if (stack == NULL) return;
    struct stack_node *cur = stack->top;
    while (cur != NULL) {
        struct stack_node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(stack);
}
