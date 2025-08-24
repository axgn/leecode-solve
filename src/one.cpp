#include <stdio.h>

int add(int a, int b) {
  int c = a;
  int d = b;
  int e = c + d;
}

int sub(int a, int b) {
  int f, g;
  int e = f + g;
  return f;
}

int main(int argc, const char **argv) {
  int c = add(9, 3);
  int d = sub(1, 6);
  printf("%d", d);
  return 0;
}
