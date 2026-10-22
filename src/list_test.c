#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

int test_add_door(void);
int test_remove_door(void);

int main() {
    int result = 0;
    result += test_add_door();
    result += test_remove_door();
    if (result == 0) {
        printf("All tests: SUCCESS");
        return SUCCESS;
    }
    printf("Tests failed: FAIL");
    return FAIL;
}

int test_add_door(void) {
    struct door d0 = {0, 0};
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct node *root = init(d0);
    if (root == NULL) return FAIL;
    struct node *n1 = add_door(root, d1);
    const struct node *n2 = add_door(n1, d2);
    if (n1 == NULL || n2 == NULL) {
        destroy(root);
        return FAIL;
    }
    int res = SUCCESS;
    // list should be: 0 -> 1 -> 2
    const struct node *cn2 = n2;
    if (root->door.id != 0 || root->next != n1 || n1->door.id != 1 || n1->next != (struct node *)cn2 ||
        cn2->door.id != 2 || cn2->next != NULL) {
        res = FAIL;
    }
    // find checks
    if (find_door(2, root) != (struct node *)cn2) res = FAIL;
    if (find_door(5, root) != NULL) res = FAIL;
    destroy(root);
    printf("test_add_door: %s", res == SUCCESS ? "SUCCESS" : "FAIL");
    return res;
}

int test_remove_door(void) {
    struct door d0 = {0, 0};
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct node *root = init(d0);
    if (root == NULL) return FAIL;
    struct node *n1 = add_door(root, d1);
    struct node *n2 = add_door(n1, d2);
    if (n1 == NULL || n2 == NULL) {
        destroy(root);
        return FAIL;
    }
    int res = SUCCESS;
    // remove middle node
    root = remove_door(n1, root);
    if (root->door.id != 0 || root->next != n2 || n2->next != NULL) {
        res = FAIL;
    }
    if (find_door(1, root) != NULL) res = FAIL;
    // remove head node
    root = remove_door(root, root);
    if (root != n2 || root->door.id != 2) {
        res = FAIL;
    }
    destroy(root);
    printf("test_remove_door: %s", res == SUCCESS ? "SUCCESS" : "FAIL");
    return res;
}
