#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

static void print_node(t_btree *node) {
    if (node == NULL) return;
    printf("        %d\n", node->item);
    print_node(node->left);
    print_node(node->right);
}

t_btree *bstree_create_node(int item) {
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    if (node == NULL) return NULL;
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// returns 1 if new leaf was created, 0 otherwise
static int bstree_try_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (cmpf(item, root->item) < 0) {
        if (root->left == NULL) {
            root->left = bstree_create_node(item);
            return 1;
        }
        return bstree_try_insert(root->left, item, cmpf);
    } else if (cmpf(item, root->item) > 0) {
        if (root->right == NULL) {
            root->right = bstree_create_node(item);
            return 1;
        }
        return bstree_try_insert(root->right, item, cmpf);
    }
    return 0;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (root == NULL || cmpf == NULL) return;
    if (bstree_try_insert(root, item, cmpf)) {
        printf("leaf %d inserted into tree:\n", item);
        print_node(root);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) return;
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) return;
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) return;
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}

void bstree_destroy(t_btree *root) {
    if (root == NULL) return;
    bstree_destroy(root->left);
    bstree_destroy(root->right);
    free(root);
}
