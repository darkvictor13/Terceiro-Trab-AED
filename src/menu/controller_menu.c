#include "controller_menu.h"

int removeEntryQueue(EntryList *queue) {
    return 1;
}

Menu *createMenu() {
    Menu* menu = (Menu *)malloc(sizeof(Menu));
    menu->first = menu->selected = NULL;
    return menu;
}

void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct) {
    int number;
    if (isEmptyEntryList(menu->first))
        number = 1;
    else
        number = menu->first->prev->number + 1;
    menu->first = addEntryList(menu->first, number, message, funct);
    if (number == 1)
        menu->selected = menu->first;
}

void setHeader(Menu *menu, HeaderFunct header) {
    menu->header = header;
}

void setFooter(Menu *menu, FooterFunct footer) {
    menu->footer = footer;
}

int controlMenu(Menu *menu, ArgStack head) {
    char c;
    while(1) {
        system(CLEAR);
        printMenu(menu);
        c = getChar();
        if (c == UP) {
            menu->selected = moveEntryList(menu->selected, 1, MOVE_BACKWARD);
        }else if (c == DOWN) {
            menu->selected = moveEntryList(menu->selected, 1, MOVE_FOWARD);
        }else if(isdigit(c)) {
            int option = c - '1';
            if (isInLimits(menu->first, option)) {
                menu->selected = moveEntryList(menu->first, option, MOVE_FOWARD);
            }else {
                printLine();
                printAlignedCenter("Digito fora dos limites");
                printLine();
                printWaitMenu();
            }
        }else if(c == ENTER) {
            if (menu->selected->funct(head) == 0) return 1;
        }else{
            printLine();
            printAlignedRight("Entrada do teclado incorreta");
            printLine();
            printWaitMenu();
        }
    }
}