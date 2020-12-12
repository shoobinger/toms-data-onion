#include "ascii85.h"
#include "stdio.h"
#include "unistd.h"

void handle(char *bytes) {
  printf("%c%c%c%c", bytes[3], bytes[2], bytes[1], bytes[0]);
}

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
