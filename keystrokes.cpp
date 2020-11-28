#include <iostream>
#include <conio.h>

using namespace std;

int keycode(bool& extended)
{
  int c;
  c = getch();

  if (c == 0 || c == 224) {
    extended = true;
    c = 256 + getch();
  }

  /*
    space: 32
    enter: 13
    tab: 9
    backspace: 8
    left arrow: 331
    up arrow: 328
    right arrow: 333
    down arrow: 336
    0-9: 48-57
    */

  return c;
}

int main()
{
  int c;
  bool extended;

  while ((c = keycode(extended)) != 0x1B) {
    if (extended)
      cout << "Extended: ";
    else
      cout << "Not extended: ";
    
    cout << c << endl;
  }
}
