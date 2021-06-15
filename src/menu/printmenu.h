#ifndef PRINT_MENU_H
#define PRINT_MENU_H

/**
 * @file printmenu.h
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por definir todas as formas de imprimir no Menu
 * @version 0.1
 * @date 13/06/2021
 */

#include "definemenu.h"
#include "circularlist.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Imprime o cabeçalho do menu
 *
 * @param message Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printHead(const char *message);

/**
 * @brief Imprime mensagem
 *
 * @param message ponteiro para char, informação impressa no menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printString(const char *message);

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedRight(const char *message);

/**
 * @brief Imprime uma linha com um mensagem alinhada no centro
 *
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedCenter(const char *message);

/**
 * @brief Imprime uma linha com um mensagem alinhada à esquerda
 *
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedLeft(const char *message);

/**
 * @brief Imprime uma linha separadora, preenchida com '-'
 *
 * @pre Nenhuma
 * @post Uma única linha separadora impressa no menu
 */
void printLine();

/**
 * @brief Imprime um caractere (qnt) vezes
 *
 * @param c caractere a ser impresso no Menu
 * @param number quantidade de vezes que o caractere deve ser impresso
 * @pre Nenhuma
 * @post Caractere impresso (qnt) vezes na tela
 */
void printExtended(char c, int number);

/**
 * @brief printa o menu principal
 * 
 * @param menu ponteiro para uma estrutura que contém as informações de um menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMenu(Menu *menu);

/**
 * @brief Selecionar a opção desejada
 * 
 * @param message informação impressa no menu, resume o que a função faz
 * @param selected inteiro que define a opção selecionada ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(List *item, int selected);

/**
 * @brief Imprime todas as opções da Lista de opções dentro do Menu
 * 
 * @param first Cabeça da Lista
 * @param selected Item selecionado do menu
 * @pre Lista de Menu carregada
 * @post Todas as opções do Menu impressas na tela
 */
void printListOptions(List *first, List *selected);

/**
 * @brief Imprime um menu para pausar o programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printWaitMenu();

/**
 * @brief Imprime a mensagem que indica o encerramento do programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEndMessage();

#endif