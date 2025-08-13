#include <stdbool.h>
#include <stdio.h>

void s_bin_print(int x, char *out_str) {
  for (int i = 31; i >= 0; i--)
    out_str[31 - i] = ((x >> i) & 1) + '0';
}

void bin_print(int x) {
  for (int i = 31; i >= 0; i--)
    putchar(((x >> i) & 1) + '0');
}

#define print_bin(expr)                                                        \
  printf("%32s = ", #expr);                                                    \
  bin_print(expr);                                                             \
  puts("");

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

  print_bin(123142);
  puts("");
  print_bin(123142 - 1);
  print_bin(123142 & (123142 - 1));
  printf("is_pow_2: %b", is_pow_2(123142));
  printf("is_pow_2: %b", is_pow_2(123142));

  return 0;
}
