#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define READ_FILE_BYTE_COUNT 5
// read first 5 bytes into buf
// if error, return -1, otherwise return read count
int TestFile(const char *filename, char buf[READ_FILE_BYTE_COUNT]) {
  FILE *f = fopen(filename, "rb");
  if (f == NULL) {
    puts("file: open err");
    return -1;
  }
  size_t n = fread(buf, 1, READ_FILE_BYTE_COUNT, f);
  if (n != READ_FILE_BYTE_COUNT) {
    if (ferror(f)) {
      puts("file: read err");
      fclose(f);
      return -1;
    }
  }
  printf("file: first 5 bytes are ");
  for (size_t i = 0; i < n; ++i) {
    if (isprint(buf[i])) {
      putchar(buf[i]);
    } else {
      printf("\\%02x", (unsigned char)buf[i]);
    }
  }
  putchar('\n');
  fclose(f);
  return (int)n;
}
int main(int argc, char **argv) {
  if (argc != 3) {
    puts("This program tests whether "
         "stdout(printf)/argv/env(getenv)/file(fopen)/stdin(fgets)... work with"
         "with UTF-8 strings\n"
         "Usage: <exe> FileName EnvName\n"
         "FileName, EnvName, Env's value can be a Unicode string\n");
    return 1;
  }
  puts((const char *)u8"stdout: Hi世界");
  printf("argv: [1]=%s\n", argv[1]);
  printf("env: %s=%s\n", argv[2], getenv(argv[2]));
  char buf[100];
  TestFile(argv[1], buf);
  printf("(input a unicode string): ");
  char *s = fgets(buf, sizeof(buf), stdin);
  if (s == NULL) {
    puts("stdin: read err");
  } else {
    printf("stdin: %s", buf);
  }
}
