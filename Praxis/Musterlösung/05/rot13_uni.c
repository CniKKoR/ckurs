#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Converts plaintext into ROT13 ciphertext
void rot13(size_t len, char data[len]) {
  for (size_t i = 0; i < len; ++i) {
    if (data[i] == '\0') {
      break;
    }

    if (data[i] >= 'A' && data[i] <= 'Z') {
      data[i] = (((data[i] - 'A') + 13) % 26) + 'A';
    } else if (data[i] >= 'a' && data[i] <= 'z') {
      data[i] = (((data[i] - 'a') + 13) % 26) + 'a';
    }
  }
}

int main(int argc, char* argv[]) {
  int input_file_no = STDIN_FILENO;
  int output_file_no = -1;

  switch (argc) {
  case 0:
    // unreachable
    return EXIT_FAILURE;
    break;
  case 1:
    // no args
    // read from stdin
    break;
  case 2:
    // one arg
    input_file_no = open(argv[1], O_RDONLY);
    if (input_file_no < 0) {
      printf("Error opening file %s!\n", argv[1]);
      return EXIT_FAILURE;
    }
    break;
  default:
    // two or more args
    input_file_no = open(argv[1], O_RDONLY);
    if (input_file_no < 0) {
      printf("Error opening file %s!\n", argv[1]);
      return EXIT_FAILURE;
    }
    output_file_no = open(argv[2], O_CREAT | O_WRONLY, 0644);
    if (output_file_no < 0) {
      printf("Error creating file %s!\n", argv[2]);
      return EXIT_FAILURE;
    }
  }

  while (true) {
    char input_buf[65] = {};
    size_t read_len = read(input_file_no, input_buf, 64);
    rot13(read_len, input_buf);
    if (output_file_no < 0) {
      printf("%64s", input_buf);
    } else {
      write(output_file_no, input_buf, 64);
    }
    if (read_len < 64) {
      break;
    }
  }

  // Remember to close your opened files
  if (input_file_no != STDIN_FILENO) {
    close(input_file_no);
  }

  if (output_file_no > -1) {
    close(output_file_no);
  }

  return EXIT_SUCCESS;
}
