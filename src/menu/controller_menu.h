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

int controlMenu(Menu *menu, ArgStack head);

int removeList(EntryList *queue);

Menu *createMenu();

void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct);

void setHeader(Menu *menu, HeaderFunct header);

void setFooter(Menu *menu, FooterFunct footer);

#endif