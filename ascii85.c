#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int process_ascii85_input(int fd, void (*handle)(char *)) {
  char buffer[5];
  // Skip two-byte starting sybols.
  read(fd, buffer, 2);

  for (;;) {
    int bytes_count = read(fd, buffer, 5);
    if (bytes_count == -1) {
      printf("Error reading from stdin");
      return 1;
    }

    // Skip ending symbols.
    if (bytes_count < 5) {
      break;
    }

    uint32_t res = 0;
    for (int i = 0; i < bytes_count; i++) {
      res += (buffer[i] - 33) * pow(85, 4 - i);
    }
    char *bytes = (char *)&res;

    handle(bytes);
  }
  return 0;
}
