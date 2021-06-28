#ifndef UTILITIES_H
#define UTILITIES_H

#ifdef __gnu_linux__

#include <termios.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

#else

#include <conio.h>
#include <wchar.h>
#include <windows.h>

#endif //__gnu_linux__

char getChar();

#endif