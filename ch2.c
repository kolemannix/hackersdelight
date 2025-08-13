#include <stdbool.h>
#include <stdio.h>

void bin_print(int x) {
  for (int i = 31; i >= 0; i--)
    putchar(((x >> i) & 1) + '0');
}

#define Show_op(expr, op)                                                      \
  {                                                                            \
    bin_print(expr);                                                           \
    puts("");                                                                  \
    bin_print(op)                                                              \
  }

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

  return 0;
}
