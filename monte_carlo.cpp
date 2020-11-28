#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int jmax = 1000; int imax = 1000;
  double x, y;
  int hit;

  srand(time(0));

  for (int j = 0; j < jmax; j++) {
    hit = 0;
    x = 0; y = 0;

    for (int i = 0; i < imax; i++) {
      x = double(rand()) / double(RAND_MAX);
      y = double(rand()) / double(RAND_MAX);
    }

    if (y <= sqrt(1-pow(x, 2)))
      hit += 1;
      
    std::cout << (15 * double(hit) / double(imax))
              << std::endl;
  }
}