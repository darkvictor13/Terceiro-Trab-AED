#ifndef CONTROLLER_MENU_H
#define CONTROLLER_MENU_H

#include "menu_defines.h"
#include "entry_list.h"
#include "print_menu.h"

int controlMenu(Menu *menu, ArgList head);

int removeList(EntryList *queue);

Menu *createMenu();

void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct);

void setHeader(Menu *menu, HeaderFunct header);

void setFooter(Menu *menu, FooterFunct footer);

#endif