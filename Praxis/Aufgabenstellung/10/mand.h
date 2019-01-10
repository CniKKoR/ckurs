#ifndef MAND_H
#define MAND_H

#include "colour.h"
#include <math.h>
#include <stdlib.h>

double pixel_to_scale(size_t value, size_t dim_size, double minf, double maxf) {
  double totalf = 0.0;
  if (minf < 0.0 && maxf < 0.0) {
    totalf = fabs(minf) - fabs(maxf);
  } else if (minf < 0.0 && maxf >= 0) {
    totalf = fabs(minf) + maxf;
  } else {
    totalf = maxf - minf;
  }

  double pos_on_pixel_scale = (double)value / dim_size;

  return minf + (totalf * pos_on_pixel_scale);
}

colourf hue_to_rgb_flat(double hue) {
  double c = (1.0 - fabs(2.0 * L_HSL - 1.0)) * S_HSL;
  double m = L_HSL - c / 2.0;
  double hue_t = (hue * 360.0) / 60.0;
  double x = c * (1 - fabs(fmod(hue_t, 2.0) - 1.0));

  double rt = 0.0;
  double gt = 0.0;
  double bt = 0.0;

  if (hue_t >= 0 && hue_t <= 1) {
    rt = c;
    gt = x;
  } else if (hue_t >= 1 && hue_t <= 2) {
    rt = x;
    gt = c;
  } else if (hue_t >= 2 && hue_t <= 3) {
    gt = c;
    bt = x;
  } else if (hue_t >= 3 && hue_t <= 4) {
    gt = x;
    bt = c;
  } else if (hue_t >= 4 && hue_t <= 5) {
    rt = x;
    bt = c;
  } else if (hue_t >= 5 && hue_t <= 6) {
    rt = c;
    bt = x;
  }

  rt += m;
  gt += m;
  bt += m;

  colourf result = {.r = rt, .g = gt, .b = bt};
  return result;
};

void mandelbrot_et(uint8_t data[], size_t width, size_t height, double re_min,
                   double re_max, double im_min, double im_max) {
  size_t *histogram = calloc(MAX_ITERS, sizeof(size_t));

  // populate histogram during first pass

  for (size_t py = 0; py < height; ++py) {
    for (size_t px = 0; px < width; ++px) {
      double x0 = pixel_to_scale(px, IMAGE_X, re_min, re_max);
      double y0 = pixel_to_scale(py, IMAGE_Y, im_min, im_max);
      double x = 0.0;
      double y = 0.0;
      size_t iter = 0;

      while (x * x + y * y < BAILOUT_R && iter < MAX_ITERS) {
        double xtemp = x * x - y * y + x0;
        y = 2.0 * x * y + y0;
        x = xtemp;
        ++iter;
      }

      histogram[iter] += 1;
    }
  }

  size_t total_iterations = 0;
  for (size_t i = 0; i < MAX_ITERS; ++i) {
    total_iterations += histogram[i];
  }

  // second pass renders the image using the histogram
  for (size_t py = 0; py < height; ++py) {

    for (size_t px = 0; px < width; ++px) {
      double x0 = pixel_to_scale(px, IMAGE_X, re_min, re_max);
      double y0 = pixel_to_scale(py, IMAGE_Y, im_min, im_max);
      double x = 0.0;
      double y = 0.0;
      size_t iter = 0;

      while (x * x + y * y < BAILOUT_R && iter < MAX_ITERS) {
        double xtemp = x * x - y * y + x0;
        y = 2.0 * x * y + y0;
        x = xtemp;
        ++iter;
      }

      double iterf = 0.0;

      if (iter < MAX_ITERS) {
        double log_zn = log2(x * x + y * y) / 2;
        double nu = log2(log_zn / log2(2.0)) / log2(2.0);
        iterf = ((double)iter) + 1 - nu;
        iter = (size_t)iterf;
      }

      double hue1 = 0.0;
      double hue2 = 0.0;
      for (size_t i = 0; i <= iter; ++i) {
        hue1 += (double)histogram[i] / total_iterations;
        hue2 += (double)histogram[i] / total_iterations;
        if (i == iter) {
          hue2 += (double)histogram[i + 1] / total_iterations;
        }
      }

      colourf ct1 = hue_to_rgb_flat(hue1);
      colourf ct2 = hue_to_rgb_flat(hue2);
      colourf ct = linterp(&ct1, &ct2, fmod(iterf, 1.0));
      colour c = colour_from_colourf(&ct);
      size_t offset0 = (py * width + px) * 3;
      data[offset0] = c.r;
      data[offset0 + 1] = c.g;
      data[offset0 + 2] = c.b;
    }
  }

  free(histogram);
}

#endif
