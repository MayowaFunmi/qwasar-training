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
          count += printf("%d", value);
          break;
        }
        case 'f': {
          double value = va_arg(args, double);
          count += printf("%f", value);
          break;
        }
        case 's': {
          char *value = va_arg(args, char *);
          count += printf("%s", value);
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
