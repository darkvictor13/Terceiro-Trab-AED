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

void printHead(const char *message);

void printString(const char *message);

void printAlignedRight(const char *message);

void printAlignedCenter(const char *message);

void printAlignedLeft(const char *message);

void printLine();

void printExtended(char c, int number);

void printMenu(Menu *menu);

void printOption(EntryList item, int selected);

void printListOptions(EntryList first, EntryList selected);

void printWaitMenu();

void printWaitMenuWhitMessage(const char *message);

void printEndMessage();

#endif