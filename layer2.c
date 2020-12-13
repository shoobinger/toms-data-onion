#include "ascii85.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

bool parity_bit_correct(uint8_t byte) {
  int count = 0;
  for (int i = 1; i <= 7; i++) {
    count += (byte >> i) & 1;
  }
  uint8_t parity_bit = byte & 1;
  return (count & 1) == parity_bit;
}

void decode_buffer(uint8_t buf[]) {
  for (int i = 0; i < 7; i++) {
    printf("%c", (buf[i] & 254 << i) | (buf[i + 1] >> (7 - i)));
  }
}

uint8_t buffer[8];
void handle(char *bytes) {
  int count = 0;
  for (int i = 3; i >= 0; i--) {
    if (parity_bit_correct(bytes[i])) {
      buffer[count++] = bytes[i];
      if (count == 8) {
        count = 0;
        decode_buffer(buffer);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
