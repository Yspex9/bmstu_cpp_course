#include "int2str.h"
#include <stdlib.h>

char* int2str(int number) {
  int is_negative = 0;
  unsigned int temp_number = number;

  if (number < 0) {
    is_negative = 1;
    temp_number = -(unsigned int)number;  // Используем unsigned int для избежания переполнения
  }

  // Определяем длину строки
  int length = 0;
  unsigned int temp = temp_number;
  while (temp > 0) {
    length++;
    temp /= 10;
  }

  if (is_negative || number == 0) {
    length++;  // Добавляем место для знака минус или для нуля
  }

  // Выделяем память для строки
  char* result = (char*)malloc(length + 1);

  // Преобразуем число в строку
  result[length] = '\0';
  int i = length - 1;
  while (temp_number > 0) {
    result[i] = '0' + (temp_number % 10);
    temp_number /= 10;
    i--;
  }

  if (is_negative) {
    result[0] = '-';
  } else if (number == 0) {
    result[0] = '0';
  }

  return result;
}
