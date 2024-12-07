#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "str2int.h"
#include "stdio.h"

int str2int(const char *str) {
  assert(str != NULL);

  // Проверка на пустую строку
  if (*str == '\0') {
    abort();
  }

  int sign = 1;
  if (*str == '+' || *str == '-') {
    if (*str == '-') {
      sign = -1;
    }
    str++;
    // Проверка на строку, содержащую только знак
    if (*str == '\0') {
      abort();
    }
  }

  long long result = 0;
  while (*str != '\0') {
    int digit = *str - '0';
    if (digit < 0 || digit > 9) {
      abort();
    }
    if (result > (LONG_MAX - digit) / 10) {
      abort();
    }
    result = result * 10 + digit;
    str++;
  }

  result *= sign;

  if (result > INT_MAX || result < INT_MIN) {
    abort();
  }

  return (int)result;
}
