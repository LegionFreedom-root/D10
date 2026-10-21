#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int test_create_node(int item);

int main() {
    int result = 0;
    // two input values
    result += test_create_node(4);
    result += test_create_node(10);
    if (result == 0) {
        printf("All tests: SUCCESS\n");
        return SUCCESS;
    }
    printf("Tests failed: FAIL\n");
    return FAIL;
}

int test_create_node(int item) {
    int res = SUCCESS;
    t_btree *node = bstree_create_node(item);
    if (node == NULL) return FAIL;
    if (node->item != item) res = FAIL;
    if (node->left != NULL || node->right != NULL) res = FAIL;
    printf("node created with item: %d\n", node->item);
    free(node);
    return res;
}
