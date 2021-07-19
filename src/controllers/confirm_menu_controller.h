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

void confirmMenuHeader();

void confirmMenuFooter();

int confirmMenuController(ArgStack head);

int actionConfirmYes(ArgStack head);

int actionConfirmNo(ArgStack head);

#endif
