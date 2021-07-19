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

/**
 * @brief 
 * 
 * @param list 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyEntryList(EntryList list);

/**
 * @brief 
 * 
 * @return EntryList 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryList allocEntryList();

/**
 * @brief 
 * 
 * @param head 
 * @param number 
 * @param message 
 * @param funct 
 * @return EntryList 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryList addEntryList(EntryList head, int number, char *message, CallbackFunct *funct);

/**
 * @brief 
 * 
 * @param head 
 * @param number 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isInLimits(EntryList head, int number);

/**
 * @brief 
 * 
 * @param item 
 * @param qnt 
 * @param side 
 * @return EntryList 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryList moveEntryList(EntryList item, int qnt, int side);

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEntryList(EntryList head);

#endif