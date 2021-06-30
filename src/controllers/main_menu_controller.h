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