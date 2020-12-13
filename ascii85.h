#include <stdint.h>

/* Read ASCII85-encoded input from fd, decode it and call handle_byte function
 * for each decoded byte. */
int process_ascii85_input(int fd, void (*handle_byte)(uint8_t));
