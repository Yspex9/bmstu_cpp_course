 #include <assert.h>
#include "str2int.h"
#include "stdio.h"
#include <limits.h>

int str2int(const char *str) {
  int result = 0;
  int sign = 1;

  if (*str == '-') {
    sign = -1;
    str++;
  } else if (*str == '+') {
    str++;
  }

  if (*str == '\0') {
    assert(0);
  }

  while (*str != '\0') {
    if (*str < '0' || *str > '9') {
      assert(0);
    }

    int digit = *str - '0';

    if (sign == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))) {
      assert(0);
    }

    if (sign == -1 && (-result < INT_MIN / 10 || (-result == INT_MIN / 10 && digit > -(INT_MIN % 10)))) {
      assert(0);
    }

    result = result * 10 + digit;
    str++;
  }

  return sign * result;
}
