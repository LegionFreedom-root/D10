#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node *init(struct door door) {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) return NULL;
    head->door = door;
    head->next = NULL;
    return head;
}

struct node *add_door(struct node *elem, struct door door) {
    if (elem == NULL) return init(door);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) return NULL;
    new_node->door = door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node *find_door(int door_id, const struct node *root) {
    const struct node *cur = root;
    while (cur != NULL) {
        if (cur->door.id == door_id) return (struct node *)cur;
        cur = cur->next;
    }
    return NULL;
}

struct node *remove_door(struct node *elem, struct node *root) {
    if (elem == NULL || root == NULL) return root;
    if (elem == root) {
        struct node *new_root = root->next;
        free(root);
        return new_root;
    }
    struct node *cur = root;
    while (cur->next != NULL && cur->next != elem) {
        cur = cur->next;
    }
    if (cur->next == elem) {
        cur->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(struct node *root) {
    struct node *cur = root;
    while (cur != NULL) {
        struct node *next = cur->next;
        free(cur);
        cur = next;
    }
}
