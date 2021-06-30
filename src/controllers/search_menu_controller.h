#ifndef SEARCH_MENU_CONTROLLER_H
#define SEARCH_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

void searchMenuHeader();

void searchMenuFooter();

int searchMenuController(ArgStack head);

int actionSearchProductByCode(ArgStack head);

int actionListProducts(ArgStack head);

int actionPrintTree(ArgStack head);

int actionPrintFreeSpaces(ArgStack head);

int actionSearchReturn(ArgStack head);

#endif
