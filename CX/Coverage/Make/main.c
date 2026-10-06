#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
void f2(const char *argv1);
void f1(int x) {
  if (x > 1) {
    puts("f1 branch 1");
  } else {
    puts("f1 branch 2");
  }
}
static void SigHandler(int signo) {
  // so that .gcda files can be saved when the process is killed
  exit(signo);
}
int main(int argc, const char **argv) {
  signal(SIGINT, SigHandler);
  signal(SIGTERM, SigHandler);
  f1(argc);
  if (argc > 1) {
    f2(argv[1]);
  } else {
    f2(NULL);
  }
}
