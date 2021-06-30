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
