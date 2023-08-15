#include <stdio.h>

// 在左边填充空格
void ljust(char *str, int width) {
  int len = strlen(str);
  for (int i = 0; i < width - len; i++) {
    str[len + i] = ' ';
  }
  str[width] = '\0';
}

// 在右边填充空格
void rjust(char *str, int width) {
  int len = strlen(str);
  for (int i = len - 1; i >= 0; i--) {
    str[i + width - len] = str[i];
  }
  for (int i = 0; i < width - len; i++) {
    str[i] = ' ';
  }
  str[width] = '\0';
}

// 居中对齐
void center(char *str, int width) {
  int len = strlen(str);
  ljust(str, width / 2);
  rjust(str + len, width - len);
}

int main() {
  char str[] = "Hello, world!";
  int width = 10;

  ljust(str, width);
  printf("%s\n", str);

  rjust(str, width);
  printf("%s\n", str);

  center(str, width);
  printf("%s\n", str);

  return 0;
}
