#include "ascii85.h"
#include <stdio.h>
#include <unistd.h>

uint8_t transform(uint8_t byte) {
  // 01010101 = 85
  // 10101010 = 170
  uint8_t flipped = (byte & 170) | ((byte ^ 255) & 85);
  uint8_t last = flipped & 1;
  return (flipped >> 1) | (last << 7);
}

void handle(uint8_t byte) { printf("%c", transform(byte)); }

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
