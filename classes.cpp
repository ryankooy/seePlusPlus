#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define STACKSIZE 10

using namespace std;

class Screen {
  public:
    void home() { cursor = screen; }
    inline void move(int, int);
    inline void forward();
    inline void back();
    inline void bottom();
    inline void up();
    void checkRange(int, int);
    void copy(Screen&);
    char get() { return *cursor; }
    char get(int, int);
    inline int row();
    int getHeight() { return height; }
    int getWidth() { return width; }
    Screen(int=8, int=40, char='#');
  private:
    short height, width;
    char *cursor, *screen;
};

class StackScreen {
  int topStack;
  void (*handler)();
  Screen stack[STACKSIZE];
};

class LinkScreen {
  Screen window;
  LinkScreen *next, *prev;
};

void Screen::checkRange(int row, int col)
{
  if (row < 1 || row > height || col < 1 || col > width) {
    cerr << "Screen coordinates ( " << row << ", " << col <<
      " ) out of bounds." << endl;
    exit(-1);
  }
}

inline void
Screen::move(int r, int c)
{
  checkRange(r, c);
  int row = (r - 1)*width;
  cursor = screen + row + c - 1;
}

inline char
Screen::get(int r, int c)
{
  move(r, c);
  return get();
}

Screen myScreen;
Screen bufScreen = myScreen;
Screen *ptr = new Screen;

int isEqual(Screen& s1, Screen *s2)
{
  if (s1.getHeight() != s2->getHeight() || s1.getWidth() != s2->getWidth())
    return 0;

  for (int ix = 0; ix < s1.getHeight(); ++ix)
    for (int j = 0; j < s2->getWidth(); ++j)
      if (s1.get(ix, j) != s2->get(ix, j))
        return 0;

  return 1;
}

void Screen::copy(Screen& s)
{
  delete screen;
  height = s.height;
  width = s.width;

  screen = cursor = new char[height * width + 1];
  assert(screen != 0);
  strcpy(screen, s.screen);
}

Screen::Screen(int high, int wid, char bkground)
{
  int sz = high * wid;
  height = high; width = wid;
  cursor = screen = new char[sz+1];
  assert(cursor != 0);

  char *ptr = screen;
  char *endptr = screen + sz;

  while (ptr != endptr)
    *ptr++ = bkground;

  *ptr = '\0';
}

inline void Screen::forward()
{
  ++cursor;

  if (*cursor == '\0')
    home();
}

inline void Screen::back()
{
  if (cursor == screen)
    bottom();
  else
    --cursor;  
}

inline void Screen::bottom()
{
  int sz = width * height - 1;
      cursor = screen + sz;
}

const char BELL = '\007';

inline void Screen::up()
{
  if (row() == 1)
    cout.put(BELL);
  else
    cursor -= width;
}

inline int Screen::row()
{
  int pos = cursor - screen + 1;
  return (pos + width - 1) / width;
}

// ...

int main()
{
  myScreen = *ptr;
  ptr = &bufScreen;

  Screen s(24, 80, '*');

  return 0;
};
