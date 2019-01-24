#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "globals.h"
#include "mand.h"
#include "stb_image_write.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  double re_min = RE_MIN;
  double re_max = RE_MAX;
  double im_min = IM_MIN;
  double im_max = IM_MAX;

  uint8_t *data = malloc(IMAGE_X * IMAGE_Y * 3);
  for (size_t i = 0; i < FRAMES; ++i) {
    struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    mandelbrot_et(data, IMAGE_X, IMAGE_Y, re_min, re_max, im_min, im_max);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    clock_t end = clock();
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Frame%03zu: %fsecs\n", i, elapsed);

    char file_des[12] = {};
    sprintf(file_des, "img/%03zu.png", i);

    stbi_write_png(file_des, IMAGE_X, IMAGE_Y, 3, data, 0);

    re_min += 0.0242;
    re_max -= 0.0092;
    im_min += 0.01775;
    im_max -= 0.00135;
  }
  free(data);
  return EXIT_SUCCESS;
}
