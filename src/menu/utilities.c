/**
 * @file utilities.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "utilities.h"

#ifdef __gnu_linux__

/**
 * @brief Lê um caractere ASCII do teclado
 * 
 * @return char Valor ASCII do caractere lido
 * @pre Nenhuma
 * @post Nenhuma
 */
char getChar() {
    char character = 0;
    struct termios old = {0};
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&character,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return character;
}

#else


/**
 * @brief Lê um caractere ASCII do teclado
 * 
 * @return char Valor ASCII do caractere lido
 * @pre Nenhuma
 * @post Nenhuma
 */
char getChar() {
    DWORD mode, cc;
    HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
    if (h == NULL)
        return 0; // console not found
    GetConsoleMode( h, &mode );
    SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
    TCHAR c = 0;
    ReadConsole( h, &c, 1, &cc, NULL );
    SetConsoleMode( h, mode );
    return c;
}

#endif //__gnu_linux__