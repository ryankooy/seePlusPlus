#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  int *ip = (int*) malloc(100);
  size_t iplen = sizeof ip / sizeof ip[0];
  *ip = 120;

  cout << "Hi, did someone ask for a " << iplen << " with their " << *ip << "\?\n";
  free(ip);
  cout << "Hi, did someone ask for a " << iplen << " with their " << *ip << "\?\n";

  return 0;
}