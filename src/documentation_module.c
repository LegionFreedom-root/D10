/* stage: documentation_module */
#include "documentation_module.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOCUMENTS 16

int validate(char *data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int *check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    if (validate == NULL || document_count <= 0) return NULL;
    int count = document_count;
    if (count > MAX_DOCUMENTS) count = MAX_DOCUMENTS;
    int *availability_mask = (int *)malloc(sizeof(int) * count);
    if (availability_mask == NULL) return NULL;
    va_list args;
    va_start(args, document_count);
    for (int i = 0; i < count; i++) {
        char *document = va_arg(args, char *);
        availability_mask[i] = validate(document);
    }
    va_end(args);
    return availability_mask;
}
