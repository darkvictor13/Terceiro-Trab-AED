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

void mainMenuHeader();

void mainMenuFooter();

int mainMenuController(ArgStack head);

int actionInsert(ArgStack head);

int actionSearch(ArgStack head);

int actionChange(ArgStack head);

int actionLoad(ArgStack head);

int actionRemove(ArgStack head);

int actionClose(ArgStack head);

#endif