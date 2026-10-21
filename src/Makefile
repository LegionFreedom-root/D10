CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BUILD_DIR = ../build

all: Quest_1 Quest_2 Quest_3 Quest_4 Quest_5 Quest_6 Quest_7 Quest_8

door_struct: Quest_1
Quest_1: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) dmanager_module.c -o $(BUILD_DIR)/Quest_1

list_test: Quest_2
Quest_2: list_test.c list.c list.h door_struct.h
	$(CC) $(CFLAGS) list_test.c list.c -o $(BUILD_DIR)/Quest_2

stack_test: Quest_3
Quest_3: stack_test.c stack.c stack.h
	$(CC) $(CFLAGS) stack_test.c stack.c -o $(BUILD_DIR)/Quest_3

print_module: Quest_4
Quest_4: main_module_entry_point.c print_module.c print_module.h
	$(CC) $(CFLAGS) main_module_entry_point.c print_module.c -o $(BUILD_DIR)/Quest_4

documentation_module: Quest_5
Quest_5: main_module_entry_point.c print_module.c documentation_module.c documentation_module.h
	$(CC) $(CFLAGS) -DDOCUMENTATION_MODULE main_module_entry_point.c print_module.c documentation_module.c -o $(BUILD_DIR)/Quest_5

bst_create_test: Quest_6
Quest_6: bst_create_test.c bst.c bst.h
	$(CC) $(CFLAGS) bst_create_test.c bst.c -o $(BUILD_DIR)/Quest_6

bst_insert_test: Quest_7
Quest_7: bst_insert_test.c bst.c bst.h
	$(CC) $(CFLAGS) bst_insert_test.c bst.c -o $(BUILD_DIR)/Quest_7

bst_traverse_test: Quest_8
Quest_8: bst_traverse_test.c bst.c bst.h
	$(CC) $(CFLAGS) bst_traverse_test.c bst.c -o $(BUILD_DIR)/Quest_8

clean:
	rm -f $(BUILD_DIR)/Quest_*

.PHONY: all clean door_struct list_test stack_test print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
