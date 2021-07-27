/**
 * @file change_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CHANGE_MENU_CONTROLLER_H
#define CHANGE_MENU_CONTROLLER_H

#include "confirm_menu_controller.h"
#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

/**
 * @brief imprime o cabecalho do menu de alteracoes
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuHeader();

/**
 * @brief imprime o rodape do menu de alteracoes
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuFooter();

/**
 * @brief cria um menu de alteracoes e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int changeMenuController(ArgStack head);

/**
 * @brief entrada do menu de alteracoes para alterar o numero de elementos em estoque
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeNumber(ArgStack head);

/**
 * @brief entrada do menu de alteracoes para alterar o valor do elemento em estoque
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeValue(ArgStack head);

/**
 * @brief entrada do menu de alteracoes para alterar o local onde sen encontra o produtos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeLocal(ArgStack head);

/**
 * @brief entradda do menu de alteracoes para voltar ao menu anterior
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeReturn(ArgStack head);

#endif
