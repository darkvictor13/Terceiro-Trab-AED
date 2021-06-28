#ifndef SEARCH_MENU_CONTROLLER
#define SEARCH_MENU_CONTROLLER

#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"

void searchMenuHeader();

void searchMenuFooter();

int searchMenuController(ArgList head);

int actionSearchProductByName(ArgList head);

int actionSearchProductByCode(ArgList head);

int actionListProducts(ArgList head);

int actionPrintTree(ArgList head);

int actionPrintFreeSpaces(ArgList head);

int actionSearchReturn(ArgList head);

#endif
