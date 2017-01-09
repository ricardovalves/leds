#include "Utils.h"

uint8_t toHexDigit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if (c >= 'a' && c <= 'z') {
    return 10 + c - 'a';
  }

  return 10 + c - 'A';
}

uint8_t toHexByte(const char *str) {
  return (toHexDigit(str[0]) << 4) | toHexDigit(str[1]);
}

CHSV toHSV(const char* value) {
  if (value != NULL && strlen(value) >= 6) {
    return CHSV(toHexByte(value), toHexByte(value + 2), toHexByte(value + 4));
  }

  return CHSV(0, 0, 0);
}
