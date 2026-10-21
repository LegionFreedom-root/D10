#include <stdio.h>
#include <stdlib.h>

#include "print_module.h"

#ifdef DOCUMENTATION_MODULE
#include "documentation_module.h"
#endif

int main() {
    print_log(print_char, Module_load_success_message);

#ifdef DOCUMENTATION_MODULE
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    if (availability_mask == NULL) return 1;

    const char *documents[Documents_count] = {"Linked lists", "Queues", "Maps", "Binary Trees"};
    for (int i = 0; i < Documents_count; i++) {
        printf("%-15s : %s\n", documents[i], availability_mask[i] ? "available" : "unavailable");
    }

    free(availability_mask);
#endif

    return 0;
}
