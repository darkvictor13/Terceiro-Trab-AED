/**
 * @file controllermenu.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar todas funções que controlam o menu
 * @version 0.1
 * @date 14/06/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "controllermenu.h"

#ifdef __gnu_linux__

/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
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
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
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

/**
 * @brief Realiza o controle de um menu previamente criado
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param dataFile ponteiro para um arquivo binário com os dados da arvore
 * @return int (ver se não é void)
 * @pre todas as informações do menu previamente carregadas e 
 * ponteiro para arquivo aberto
 * @post o menu chamado será executado, bem como a função selecionada
 */
int controlMenu(Menu *menu, FILE *dataFile) {
    char c;
    while(1) {
        system(CLEAR);
        printMenu(menu);
        c = getChar();
        if (c == UP) {
            menu->selected = moveTo(menu->selected, 1, MOVE_BACKWARD);
        }else if (c == DOWN) {
            menu->selected = moveTo(menu->selected, 1, MOVE_FOWARD);
        }else if(isdigit(c)) {
            int option = c - '1';
            if (isInLimits(menu->first, option)) {
                menu->selected = moveTo(menu->first, option, MOVE_FOWARD);
            }else {
                printLine();
                printAlignedCenter("Digito fora dos limites");
                printLine();
                printWaitMenu();
            }
        }else if(c == ENTER) {
            //if(executeEntry(menu->queue, menu->thisOption, dataFile) == 0)
                //return 1;
            if (menu->selected->funct(dataFile) == 0) return 1;
        }else{
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }
    }
}