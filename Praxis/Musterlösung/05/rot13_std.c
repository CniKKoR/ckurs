#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
  FILE *input_file = stdin;
  FILE *output_file = NULL;

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
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      printf("Error opening file %s!\n", argv[1]);
      return EXIT_FAILURE;
    }
    break;
  default:
    // two or more args
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
      printf("Error opening file %s!\n", argv[1]);
      return EXIT_FAILURE;
    }
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
      printf("Error creating file %s!\n", argv[2]);
      return EXIT_FAILURE;
    }
  }

  for (;;) {
    char input_buf[65] = {};
    char *success = fgets(input_buf, 65, input_file);
    rot13(64, input_buf);
    if (output_file == NULL) {
      printf("%s", input_buf);
    } else {
      fputs(input_buf, output_file);
    }
    if (success == NULL) {
      if (feof(input_file)) {
        break;
      } else {
        printf("Encountered error when reading file!");
        fclose(input_file);
        if (output_file != NULL) {
          fclose(output_file);
        }
        return EXIT_FAILURE;
      }
    }
  }

  // Remember to close your opened files
  if (input_file != stdin) {
    fclose(input_file);
  }

  if (output_file != NULL) {
    fclose(output_file);
  }

  return EXIT_SUCCESS;
}
