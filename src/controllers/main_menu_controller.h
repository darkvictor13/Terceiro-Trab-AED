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
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuHeader();

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuFooter();

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int mainMenuController(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionInsert(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearch(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChange(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionLoad(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionRemove(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionClose(ArgStack head);

#endif