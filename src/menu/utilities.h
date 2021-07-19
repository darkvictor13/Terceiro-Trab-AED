/**
 * @file utilities.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

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

/**
 * @brief 
 * 
 * @return char 
 * @pre Nenhuma
 * @post Nenhuma
 */
char getChar();

#endif