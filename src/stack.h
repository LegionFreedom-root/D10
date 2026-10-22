/* stage: stack_test */
#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack_node {
    // cppcheck-suppress unusedStructMember
    int value;
    // cppcheck-suppress unusedStructMember
    struct stack_node *next;
};

struct stack {
    // cppcheck-suppress unusedStructMember
    struct stack_node *top;
    // cppcheck-suppress unusedStructMember
    int size;
};

// create new stack
struct stack *init(void);
// push integer to stack
int push(struct stack *stack, int value);
// pop integer from stack, stores it into *value
int pop(struct stack *stack, int *value);
// free stack memory
void destroy(struct stack *stack);

#endif  // SRC_STACK_H_