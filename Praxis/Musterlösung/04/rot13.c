#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Converts plaintext into ROT13 ciphertext
void rot13(size_t len, char data[len]) {
  for (size_t i = 0; i < len; ++i) {
    if (data[i] == 0) {
      break;
    }

    if (data[i] >= 'A' && data[i] <= 'Z') {
      data[i] = (((data[i] - 'A') + 13) % 26) + 'A';
    } else if (data[i] >= 'a' && data[i] <= 'z') {
      data[i] = (((data[i] - 'a') + 13) % 26) + 'a';
    }
  }
}

int main(void) {
  char input_buf[64] = {};
  printf("Enter text consisting of any letter A-Z:\n");
  fgets(input_buf, 64, stdin);
  rot13(64, input_buf);
  printf("%s", input_buf);
  return EXIT_SUCCESS;
}
