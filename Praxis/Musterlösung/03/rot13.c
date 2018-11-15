#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Converts plaintext into ROT13 ciphertext
bool rot13(size_t len, char data[len]) {
  bool success = true;
  for (size_t i = 0; i < len; ++i) {
    if (data[i] == '\0') {
      break;
    }
    if (data[i] < 65 || data[i] > 90) {
      success = false;
      break;
    }
    data[i] = (((data[i] - 65) + 13) % 26) + 65;
  }
    return success;
}

int main(void) {
  char input_buf[64] = {};
  printf("Enter text consisting of any letter A-Z:\n");
  scanf("%s", input_buf);
  if (rot13(64, input_buf)) {
    printf("%s\n", input_buf);
    return EXIT_SUCCESS;
  } else {
    printf("Wrong input!");
    return EXIT_FAILURE;
  }
}
