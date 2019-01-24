#include <limits.h>
#include <stdint.h>

#ifndef COLOUR
#define COLOUR

typedef struct colourf {
  double r;
  double g;
  double b;
} colourf;

typedef struct colour {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} colour;

colourf linterp(colourf *a, colourf *b, double t) {
  colourf result = {
      .r = (1.0 - t) * a->r + t * b->r,
      .g = (1.0 - t) * a->g + t * b->g,
      .b = (1.0 - t) * a->b + t * b->b,
  };
  return result;
}

colour colour_from_colourf(colourf *c) {
  colour result = {
      .r = (uint8_t)((double)UINT8_MAX * c->r),
      .g = (uint8_t)((double)UINT8_MAX * c->g),
      .b = (uint8_t)((double)UINT8_MAX * c->b),
  };
  return result;
}

#endif
