/**
 * @file print_menu.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PRINT_MENU_H
#define PRINT_MENU_H

#include "menu_defines.h"
#include "entry_list.h"

/**
 * @brief Função padrão para imprimir o cabeçalho
 * do menu
 * 
 * @param message Mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printHead(const char *message);

/**
 * @brief Imprime uma string na tela
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printString(const char* message);

/**
 * @brief Imprime a mensagem alinhada a Esquerda
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printAlignedLeft(const char *message);

/**
 * @brief Imprime a mensagem alinhada ao centro do console
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printAlignedCenter(const char *message);

/**
 * @brief Imprime a mensagem alinhada a direita
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printAlignedRight(const char *message);

/**
 * @brief Imprime uma linha do Menu
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printLine();

/**
 * @brief Imprime um caractere "number" vezes
 * 
 * @param c caractere a ser impresso
 * @param number quantidade de vezes a ser impresso
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printExtended(char c, int number);

/**
 * @brief Imprime o menu completo
 * 
 * @param menu 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printMenu(Menu *menu);

/**
 * @brief Imprime A lista de opções do menu
 * 
 * @param first primeira opção do menu
 * @param selected opção selecionada do menu
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printListOptions(EntryList first, EntryList selected);

/**
 * @brief Imprime uma única opção do menu
 * 
 * @param item o item do menu
 * @param selected boleano se ele está selecionado
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printOption(EntryList item, int selected);

/**
 * @brief Imprime um menu que aguarda a entrada do usuário para continuar
 * equivalente ao system(PAUSE) porém multi-plataforma
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printWaitMenu();

/**
 * @brief Imprime um menu que aguarda a entrada do usuário para continuar
 * porém com uma mensagem extra passada como parâmetro
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printWaitMenuWhitMessage(const char *message);

/**
 * @brief Imprime a mensagem final do programa
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printEndMessage();

#endif