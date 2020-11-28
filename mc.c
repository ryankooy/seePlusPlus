#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi(double tolerance)
{
  double x, y, val, error;
  unsigned long sampled = 0, hit = 0, i;

  do {
    for (i = 10000000; i; i--, sampled++) {
      x = rand() / (RAND_MAX + 1.0);
      y = rand() / (RAND_MAX + 1.0);

      if (x * x + y * y < 1)
        hit++;
    }

    val = (double) hit / sampled;
    error = sqrt(val * (1-val) / sampled) * 4;
    val *= 4;

    fprintf(stderr, "Pi = %f +/- %5.3e at %1dM samples.\r",
      val, error, sampled/1000000);
  } while (!hit || error > tolerance);

  return val;
}

int main()
{
  pi(3e-4);
  return 0;
}