#include <stdlib.h>
#include <limits.h>
#include <assert.h>

int str2int(const char *str) {
  char *endptr;
  long result = strtol(str, &endptr, 10);

  if (*str == '\0' || *endptr != '\0') {
    assert(0);
  }

  if (result < INT_MIN || result > INT_MAX) {
    assert(0);
  }

  return (int)result;
}
