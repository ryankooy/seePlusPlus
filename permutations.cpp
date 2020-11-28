#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
void print(const vector<T> &vec)
{
  for (typename vector<T>::const_iterator i = vec.begin();
    i != vec.end(); ++i) {

    cout << *i;

    if ((i + 1) != vec.end())
      cout << ",\n";
  }
}

int main()
{
  ofstream afile;
  string thing("ryankooy");

  afile.open("rankyoyo.txt");

  sort(thing.begin(), thing.end());

  do {
    afile << thing << '\n';
  } while (next_permutation(thing.begin(), thing.end()));

  afile.close();

  return 0;
}
