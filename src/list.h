/* stage: list_test */
#ifndef SRC_LIST_H_
#define SRC_LIST_H_

#include "door_struct.h"

struct node {
    struct door door;
    struct node *next;
};

// init list with first node
struct node *init(struct door door);
// add new node after elem
struct node *add_door(struct node *elem, struct door door);
// find door in list by id
struct node *find_door(int door_id, struct node *root);
// remove elem from list, returns new root
struct node *remove_door(struct node *elem, struct node *root);
// free all list memory
void destroy(struct node *root);

#endif  // SRC_LIST_H_
