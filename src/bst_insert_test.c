#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

int cmpf(int a, int b) { return a - b; }

void build_tree(t_btree *root, const int *items, int count);

int test_insert_set1(void);
int test_insert_set2(void);

int main() {
    int result = 0;
    result += test_insert_set1();
    result += test_insert_set2();
    if (result == 0) {
        printf("All tests: SUCCESS\n");
        return SUCCESS;
    }
    printf("Tests failed: FAIL\n");
    return FAIL;
}

void build_tree(t_btree *root, const int *items, int count) {
    for (int i = 0; i < count; i++) {
        bstree_insert(root, items[i], cmpf);
    }
}

int test_insert_set1(void) {
    int res = SUCCESS;
    const int items[] = {2, 6, 4};
    t_btree *root = bstree_create_node(4);
    if (root == NULL) return FAIL;
    build_tree(root, items, 3);
    // 2 -> left of 4, 6 -> right of 4, 4 -> equal to root, not inserted
    if (root->left == NULL || root->left->item != 2) res = FAIL;
    if (root->right == NULL || root->right->item != 6) res = FAIL;
    if (root->left->left != NULL || root->left->right != NULL) res = FAIL;
    if (root->right->left != NULL || root->right->right != NULL) res = FAIL;
    bstree_destroy(root);
    return res;
}

int test_insert_set2(void) {
    int res = SUCCESS;
    const int items[] = {5, 1, 3};
    t_btree *root = bstree_create_node(4);
    if (root == NULL) return FAIL;
    build_tree(root, items, 3);
    // 5 -> right of 4, 1 -> left of 4, 3 -> right of 1
    if (root->right == NULL || root->right->item != 5) return FAIL;
    if (root->left == NULL || root->left->item != 1) return FAIL;
    if (root->left->right == NULL || root->left->right->item != 3) return FAIL;
    bstree_destroy(root);
    return res;
}
