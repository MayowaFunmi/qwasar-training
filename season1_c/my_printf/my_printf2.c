#include <stdarg.h>
#include <stdio.h>

int my_printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'd': {
          int value = va_arg(args, int);
          count += print_int(value);
          break;
        }
        case 'f': {
          double value = va_arg(args, double);
          count += print_float(value);
          break;
        }
        case 's': {
          char *value = va_arg(args, char *);
          count += print_string(value);
          break;
        }
        default: {
          putchar(*format);
          count++;
          break;
        }
      }
    } else {
      putchar(*format);
      count++;
    }
    format++;
  }
  va_end(args);
  return count;
}

int print_int(int value) {
  // Implement your own function to print an integer.
}

int print_float(double value) {
  // Implement your own function to print a floating-point number.
}

int print_string(char *value) {
  // Implement your own function to print a string.
}

/*
my_printf("Hello, World!\n");
my_printf("I am %d years old.\n", 30);
my_printf("Pi is approximately %f.\n", 3.141592);

*/