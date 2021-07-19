/**
 * @file entry_list.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ENTRY_LIST_H
#define ENTRY_LIST_H

#include "menu_defines.h"

int isEmptyEntryList(EntryList head);

EntryList allocEntryList();

EntryList addEntryList(EntryList head, int number, char *message, CallbackFunct *funct);

int isInLimits(EntryList head, int number);

void printEntryList(EntryList head);

EntryList moveEntryList(EntryList item, int qnt, int side);

#endif