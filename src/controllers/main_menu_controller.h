#ifndef MAIN_MENU_CONTROLLER_H
#define MAIN_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "search_menu_controller.h"
#include "change_menu_controller.h"

void mainMenuHeader();

void mainMenuFooter();

int mainMenuController(ArgList head);

int actionInsert(ArgList head);

int actionSearch(ArgList head);

int actionChange(ArgList head);

int actionLoad(ArgList head);

int actionRemove(ArgList head);

int actionClose(ArgList head);

#endif