/**
 * @file print_menu.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PRINT_MENU_H
#define PRINT_MENU_H

#include "menu_defines.h"
#include "entry_list.h"

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printHead(const char *message);

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printString(const char* message);

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printAlignedLeft(const char *message);

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printAlignedCenter(const char *message);

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printAlignedRight(const char *message);

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printLine();

/**
 * @brief 
 * 
 * @param c 
 * @param number 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printExtended(char c, int number);

/**
 * @brief 
 * 
 * @param menu 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMenu(Menu *menu);

/**
 * @brief 
 * 
 * @param first 
 * @param selected 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printListOptions(EntryList first, EntryList selected);

/**
 * @brief 
 * 
 * @param item 
 * @param selected 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(EntryList item, int selected);

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printWaitMenu();

/**
 * @brief 
 * 
 * @param message 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printWaitMenuWhitMessage(const char *message);

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEndMessage();

#endif