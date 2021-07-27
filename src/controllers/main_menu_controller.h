/**
 * @file main_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MAIN_MENU_CONTROLLER_H
#define MAIN_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"
#include "search_menu_controller.h"
#include "change_menu_controller.h"

/**
 * @brief imprime o cabecalho do menu principal
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuHeader();

/**
 * @brief imprime o rodape do menu principal
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuFooter();

/**
 * @brief cria o menu principal e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int mainMenuController(ArgStack head);

/**
 * @brief entrada do menu principal para acessar ao menu de insercao
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionInsert(ArgStack head);

/**
 * @brief entrada do menu principal para acessar ao menu de busca
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearch(ArgStack head);

/**
 * @brief entrada do menu principal para acessar ao menu de alteracoes
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChange(ArgStack head);

/**
 * @brief entrada do menu principal para carregar um arquivo de dados de entrada
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionLoad(ArgStack head);

/**
 * @brief entrada do menu principal para remover um elemento da arvore de elementos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionRemove(ArgStack head);

/**
 * @brief entrada do menu principal para encerrar o programa
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionClose(ArgStack head);

#endif