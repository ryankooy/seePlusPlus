#include <windows.h>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {3, 6};
	SetConsoleCursorPosition(hConsole, pos);
	WriteConsole(hConsole, "Hell is here.", 5, NULL, NULL);
	return 0;
}