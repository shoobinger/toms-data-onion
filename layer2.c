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

uint8_t buffer[8];

/* Converts 8 bytes to 7 bytes by dropping the parity bit from each byte. Then
 * prints each resulting byte as an ASCII symbol. */
void decode_buffer() {
  for (int i = 0; i < 7; i++) {
    printf("%c", ((buffer[i] & 254) << i) | (buffer[i + 1] >> (7 - i)));
  }
}

int count = 0;
/* Checks whether the given byte has a correct parity bit, and adds it to the
 * buffer if that is the case. When the buffer is filled with 8 bytes, decode
 * them according to the layer2 rules. */
void handle(uint8_t byte) {
  if (parity_bit_correct(byte)) {
    buffer[count++] = byte;
    if (count == 8) {
      count = 0;
      decode_buffer();
    }
  }
}

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
