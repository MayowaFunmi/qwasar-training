#include <stdio.h>

char my_putchar(char c) {
    write(1, &c, 1);
}

char my_print_reverse_alphabet() {
    char c;
    for(c = 'z'; c >= 'a'; c--) {
        my_putchar(c);
    }
    my_putchar('\n');
}