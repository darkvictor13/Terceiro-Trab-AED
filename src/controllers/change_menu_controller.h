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

void changeMenuHeader();

void changeMenuFooter();

int changeMenuController(ArgStack head);

int actionChangeNumber(ArgStack head);

int actionChangeValue(ArgStack head);

int actionChangeLocal(ArgStack head);

int actionChangeReturn(ArgStack head);

#endif
