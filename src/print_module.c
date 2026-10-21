/* stage: print_module */
#include "print_module.h"

#include <stdio.h>
#include <time.h>

int print_char(char ch) { return putchar(ch); }

void print_log(int (*print)(char), char *message) {
    time_t now = time(NULL);
    const struct tm *tm_now = localtime(&now);
    // print log prefix
    for (int i = 0; LOG_PREFIX[i] != '\0'; i++) {
        print(LOG_PREFIX[i]);
    }
    print(' ');
    // print current time in HH:MM:SS format
    char timestamp[16];
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", tm_now);
    for (int i = 0; timestamp[i] != '\0'; i++) {
        print(timestamp[i]);
    }
    print(' ');
    // print message
    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }
    print('\n');
}
