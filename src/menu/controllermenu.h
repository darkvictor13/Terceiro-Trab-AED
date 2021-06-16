/**
 * @file controllermenu.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas funções que controlam o menu
 * @version 0.1
 * @date 14/06/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "printmenu.h"
#include "circularlist.h"
#include <stdlib.h>
#include <ctype.h>

#ifdef __gnu_linux__

#include <limits.h>
#include <termios.h>
#include <unistd.h>

#else

#include <conio.h>
#include <wchar.h>
#include <windows.h>

#endif //__gnu_linux__
/**
 * @brief Lê um único caractere do teclado (stdin)
 *
 * @return char caractere lido
 * @pre buffer de escrita ne tela (stdout) limpo
 * @post stdin limpo
 */
char getChar();

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
int controlMenu(Menu *menu, FILE *dataFile);