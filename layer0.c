#include "ascii85.h"
#include "stdio.h"
#include "unistd.h"

void handle(uint8_t byte) { printf("%c", byte); }

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
