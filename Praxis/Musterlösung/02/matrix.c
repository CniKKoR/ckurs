#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // Wertzuweisungen
  long matrix_a[3][3] = {{21, -566, 708}, {-5, -77, 901}, {267, 89, 623}};
  long matrix_b[3][3] = {{74, -60, 98}, {-18, 93, 706}, {12, 55, 243}};
  long matrix_c[3][3] = {};

  // Berechnung
  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 3; ++j) {
      for (size_t k = 0; k < 3; ++k) {
        matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }

  // Ausgabe
  for (size_t i = 0; i < 3; ++i) {
    printf("| %li %li %li |\n", matrix_c[i][0], matrix_c[i][1], matrix_c[i][2]);
  }
  return EXIT_SUCCESS;
}
