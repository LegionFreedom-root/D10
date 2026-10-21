#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int cmpf(int a, int b) { return a - b; }

void applyf(int item) { printf("%d ", item); }

void build_tree(t_btree *root, const int *items, int count) {
    for (int i = 0; i < count; i++) {
        bstree_insert(root, items[i], cmpf);
    }
}

int test_traverse(const int *items, int count, int root_item) {
    t_btree *root = bstree_create_node(root_item);
    if (root == NULL) return FAIL;
    build_tree(root, items, count);

    printf("infix:   ");
    bstree_apply_infix(root, applyf);
    printf("\n");

    printf("prefix:  ");
    bstree_apply_prefix(root, applyf);
    printf("\n");

    printf("postfix: ");
    bstree_apply_postfix(root, applyf);
    printf("\n");

    bstree_destroy(root);
    return SUCCESS;
}

int main() {
    int result = 0;
    // input sets from previous test
    const int set1[] = {2, 6, 4};
    const int set2[] = {5, 1, 3};
    printf("Tree 1 (root 4, items 2 6 4):\n");
    result += test_traverse(set1, 3, 4);
    printf("Tree 2 (root 4, items 5 1 3):\n");
    result += test_traverse(set2, 3, 4);
    if (result == 0) {
        printf("All tests: SUCCESS\n");
        return SUCCESS;
    }
    printf("Tests failed: FAIL\n");
    return FAIL;
}
