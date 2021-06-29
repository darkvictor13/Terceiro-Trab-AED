#ifndef CHANGE_MENU_CONTROLLER_H
#define CHANGE_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"

void changeMenuHeader();

void changeMenuFooter();

int changeMenuController(ArgList head);

int actionChangeNumber(ArgList head);

int actionChangeValue(ArgList head);

int actionChangeLocal(ArgList head);

int actionChangeReturn(ArgList head);

#endif
