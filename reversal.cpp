#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
  string s;

  cout << "Type a phrase below: " << endl;

  getline(cin, s);

  cout << "Input reversed: "
       << string(s.rbegin(), s.rend()) << endl;

  istringstream is(s);
  vector<string> words(istream_iterator<string>(is), {});

  cout << "Each word reversed: ";

  for (auto w : words)
    cout << string(w.rbegin(), w.rend()) << ' ';
  
  cout << endl << "Original word order reversed: ";

  reverse_copy(words.begin(), words.end(),
    ostream_iterator<string>(cout, " "));

  cout << endl;

  return 0;
}