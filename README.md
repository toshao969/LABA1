#include <stdio.h>
#include <math.h>

int main() {
  float x0 = 1, x1 = 3, hx = 1.3, y0 = 2, y1 = 4, hy = 1.5;

  for (float xn = x0; xn <= x1; xn += hx) {
    for (float yn = y0; yn <= y1; yn += hy) {
      printf("x = %f; y = %f; ", xn, yn);
      if (xn / (yn * yn) < 1) {
        float u1 = M_E * cos(M_PI * xn * xn) - yn;
        float u2 = tan(pow(xn * yn * yn, 1.0 / 3.0) - 1 / pow(xn, 1.0 / 3.0));
        if (u1 >= u2) {
          printf("U = %f\n", u1);
        } else {
          printf("U = %f\n", u2);
        }
      }
      else if (xn / (yn * yn) >= 1) {
        float u = sin(xn * yn - xn * xn - yn * yn);
        printf("U = %f\n", u);
      }
    }
  }
  return 0;
}
