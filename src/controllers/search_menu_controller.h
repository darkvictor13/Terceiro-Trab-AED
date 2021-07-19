/**
 * @file search_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SEARCH_MENU_CONTROLLER_H
#define SEARCH_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../models/b_tree_prints.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuHeader();

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuFooter();

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchMenuController(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchProductByCode(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionListProducts(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintTree(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintRegistryList(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintProductList(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeIndexSpaces(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeDataSpaces(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchReturn(ArgStack head);

#endif
