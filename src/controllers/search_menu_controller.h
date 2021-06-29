#ifndef SEARCH_MENU_CONTROLLER_H
#define SEARCH_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"

void searchMenuHeader();

void searchMenuFooter();

int searchMenuController(ArgList head);

int actionSearchProductByCode(ArgList head);

int actionListProducts(ArgList head);

int actionPrintTree(ArgList head);

int actionPrintFreeSpaces(ArgList head);

int actionSearchReturn(ArgList head);

#endif
