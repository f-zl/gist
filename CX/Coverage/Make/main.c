#include <stdio.h>
void f2(const char *argv1);
void f1(int x) {
  if (x > 1) {
    puts("f1 branch 1");
  } else {
    puts("f1 branch 2");
  }
}

int main(int argc, const char **argv) {
  f1(argc);
  if (argc > 1) {
    f2(argv[1]);
  } else {
    f2(NULL);
  }
}
