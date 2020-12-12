#include "ascii85.h"
#include "stdio.h"
#include "unistd.h"

void handle(char *bytes) {
  for (int i = 3; i >= 0; i--) {
    printf("%c", bytes[i]);
  }
}

int main(int argc, char *argv[]) {
  process_ascii85_input(STDIN_FILENO, handle);
  return 0;
}
