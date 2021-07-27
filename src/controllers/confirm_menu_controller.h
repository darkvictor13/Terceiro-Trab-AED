/**
 * @file confirm_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CONFIRM_MENU_CONTROLLER_H
#define CONFIRM_MENU_CONTROLLER_H

#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

/**
 * @brief imprime o cabecalho do menu de confirmacao
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void confirmMenuHeader();

/**
 * @brief imprime o rodape do menu de confirmacao
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void confirmMenuFooter();

/**
 * @brief cria o menu de confirmacao e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int confirmMenuController(ArgStack head);

/**
 * @brief entrada do menu para confirmar o que esta sendo requerido
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionConfirmYes(ArgStack head);

/**
 * @brief entrada do menu para confirmar o que esta sendo requerido
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionConfirmNo(ArgStack head);

#endif
