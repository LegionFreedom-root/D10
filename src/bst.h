#ifndef SRC_BST_H_
#define SRC_BST_H_

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

// create node with item, children set to NULL
t_btree *bstree_create_node(int item);
// insert item into BST using cmpf comparator
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
// traversing functions
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
// free all tree memory
void bstree_destroy(t_btree *root);

#endif  // SRC_BST_H_
