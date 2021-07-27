/**
 * @file controller_menu.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CONTROLLER_MENU_H
#define CONTROLLER_MENU_H

#include "menu_defines.h"
#include "entry_list.h"
#include "print_menu.h"

/**
 * @brief Remove um elemento do menu
 * 
 * @param queue lista interna de elementos do menu
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeEntryQueue(EntryList *queue);

/**
 * @brief Cria o Menu, alocando a memória do mesmo
 * 
 * @return Menu* ponteiro para um menu inicializado
 * @pre Nenhuma
 * @post Nenhuma
 */
Menu *createMenu();

/**
 * @brief Adiciona uma nova opção ao menu
 * 
 * @param menu Um ponteiro para um menu válido
 * @param message Mensagem da nova opção
 * @param funct ponteiro para a função a ser executada na opção
 * @pre Nenhuma
 * @post Nenhuma
 */
void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct);

/**
 * @brief Adiciona um cabeçalho para o menu
 * 
 * @param menu Um ponteiro para um menu válido
 * @param header ponteiro para o cabeçalho do menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void setHeader(Menu *menu, HeaderFunct header);

/**
 * @brief Adiciona um rodapé para o menu
 * 
 * @param menu Um ponteiro para um menu válido
 * @param footer ponteiro para o rodapé do menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void setFooter(Menu *menu, FooterFunct footer);

/**
 * @brief Executa o loop de um menu válido
 * 
 * @param menu Um ponteiro para um menu válido
 * @param head ponteiro para uma pilha de argumentos
 * @return int indica se deve retornar ao menu anterior
 * @pre Nenhuma
 * @post Nenhuma
 */
int controlMenu(Menu *menu, ArgStack head);

#endif