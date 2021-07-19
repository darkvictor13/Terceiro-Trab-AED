/**
 * @file controller_menu.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CONTROLLER_MENU_H
#define CONTROLLER_MENU_H

#include "menu_defines.h"
#include "entry_list.h"
#include "print_menu.h"

/**
 * @brief 
 * 
 * @param queue 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeEntryQueue(EntryList *queue);

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Menu *createMenu();

/**
 * @brief 
 * 
 * @param menu 
 * @param message 
 * @param funct 
 * @pre Nenhuma
 * @post Nenhuma
 */
void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct);

/**
 * @brief Set the Header object
 * 
 * @param menu 
 * @param header 
 * @pre Nenhuma
 * @post Nenhuma
 */
void setHeader(Menu *menu, HeaderFunct header);

/**
 * @brief Set the Footer object
 * 
 * @param menu 
 * @param footer 
 * @pre Nenhuma
 * @post Nenhuma
 */
void setFooter(Menu *menu, FooterFunct footer);

/**
 * @brief 
 * 
 * @param menu 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int controlMenu(Menu *menu, ArgStack head);

#endif