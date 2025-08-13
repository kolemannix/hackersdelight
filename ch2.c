#include <stdbool.h>
#include <stdio.h>

void sn_bin_print(int x) {
  for (int i = 31; i >= 0; i--)
    putchar(((x >> i) & 1) + '0');
}

void bin_print(int x) {
  for (int i = 31; i >= 0; i--)
    putchar(((x >> i) & 1) + '0');
}

#define print_bin(expr)                                                        \
  _Generic((expr),                                                             \
      int: printf("DEBUG: %s = %d\n", #expr, (expr)),                          \
      float: printf("DEBUG: %s = %.6f\n", #expr, (expr)),                      \
      double: printf("DEBUG: %s = %.6f\n", #expr, (expr)),                     \
      char: printf("DEBUG: %s = '%c'\n", #expr, (expr)),                       \
      char *: printf("DEBUG: %s = \"%s\"\n", #expr, (expr)),                   \
      default: printf("DEBUG: %s = %p\n", #expr, (void *)(expr)))

void show_op(int op1, int op2) {
  bin_print(op1);
  puts("");
  bin_print(op2);
  puts("");
  return;
}

bool is_pow_2(int op1) { return (op1 & (op1 - 1)) == 0; }

int main(void) {
  printf("sizeof bool: %lu\n", sizeof(bool));
  printf("sizeof char: %lu\n", sizeof(char));
  printf("sizeof int : %lu\n", sizeof(int));
  printf("sizeof long: %lu\n", sizeof(long));

  puts("Hello, ch2");

  show_op(123142, 123142 - 1);
  puts("");
  show_op(123142, 123142 & (123142 - 1));
  printf("is_pow_2: %s", is_pow_2());

  return 0;
}
