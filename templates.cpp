#include <iostream>

template <class X4>
X4 minnie(X4 *arr, int size)
{
  X4 min_val = arr[0];

  for (int i = 1; i < size; ++i)
    if (arr[i] < min_val)
      min_val = arr[i];

  return min_val;
}

int ai[] = { 10, 7, 14, 3, 25 };
double da[] = { 10.2, 7.1, 14.5, 3.2, 25.0 };

int main()
{
  int size = sizeof(ai) / sizeof(int);
  int i = minnie(ai, size);

  if (i != 3)
    std::cout << "??oops: integer minnie() failed\n";
  else
    std::cout << "!!ok: integer minnie() worked\n";

  size = sizeof(da) / sizeof(double);
  double d = minnie(da, size);

  if (d != 3.2)
    std::cout << "??oops: double minnie() failed\n";
  else
    std::cout << "!!ok: double minnie() worked\n";

  return 0;
}
