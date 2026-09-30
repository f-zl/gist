#include <stdio.h>
void f2(const char *argv1) {
  if (argv1) {
    puts("f2 branch 1");
  } else {
    puts("f2 branch 2");
  }
}
