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

void searchMenuHeader();

void searchMenuFooter();

int searchMenuController(ArgStack head);

int actionSearchProductByCode(ArgStack head);

int actionListProducts(ArgStack head);

int actionPrintTree(ArgStack head);

int actionPrintRegistryList(ArgStack head);

int actionPrintProductList(ArgStack head);

int actionPrintFreeIndexSpaces(ArgStack head);

int actionPrintFreeDataSpaces(ArgStack head);

int actionSearchReturn(ArgStack head);

#endif
