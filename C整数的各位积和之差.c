#include <stdio.h>

int main() {
  int n, sum = 0, product = 1;
  scanf("%d", &n);
  while (n > 0) {
    int digit = n % 10;
    sum += digit;
    product *= digit;
    n /= 10;
  }
  printf("%d\n", product - sum);
  return 0;
}
