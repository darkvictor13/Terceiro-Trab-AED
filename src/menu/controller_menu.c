/**
 * @file controller_menu.c
 * @author Marco-Guerra, Victor Almeida
 * @brief 
 * @version 1.0
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "controller_menu.h"

/**
 * @brief 
 * 
 * @param queue 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeEntryQueue(EntryList *queue) {
    return 1;
}

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Menu *createMenu() {
    Menu* menu = (Menu *)malloc(sizeof(Menu));
    menu->first = menu->selected = NULL;
    return menu;
}

/**
 * @brief 
 * 
 * @param menu 
 * @param message 
 * @param funct 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief 
 * 
 * @param menu 
 * @param header 
 * @pre Nenhuma
 * @post Nenhuma
 */
void setHeader(Menu *menu, HeaderFunct header) {
    menu->header = header;
}

/**
 * @brief 
 * 
 * @param menu 
 * @param footer 
 * @pre Nenhuma
 * @post Nenhuma
 */
void setFooter(Menu *menu, FooterFunct footer) {
    menu->footer = footer;
}

/**
 * @brief 
 * 
 * @param menu 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int controlMenu(Menu *menu, ArgStack head) {
    char inputChar;
    while(1) {
        system(CLEAR);
        printMenu(menu);
        inputChar = getChar();
        if(inputChar == ENTER) {
            if (menu->selected->funct(head) == 0) return 1;
        }else if (inputChar == UP) {
            menu->selected = moveEntryList(menu->selected, 1, MOVE_BACKWARD);
        }else if (inputChar == DOWN) {
            menu->selected = moveEntryList(menu->selected, 1, MOVE_FOWARD);
        }else if(isdigit(inputChar)) {
            int option = inputChar - '1';
            if(option == menu->selected->number - 1)
                if (menu->selected->funct(head) == 0) return 1;
            if (isInLimits(menu->first, option)) {
                menu->selected = moveEntryList(menu->first, option, MOVE_FOWARD);
            }else {
                printLine();
                printAlignedCenter("Digito fora dos limites.");
                printLine();
                printWaitMenu();
            }
        }else if(inputChar == ESC) {
            return 1;
        }else{
            printLine();
            printAlignedRight("Entrada do teclado incorreta.");
            printLine();
            printWaitMenu();
        }
    }
}