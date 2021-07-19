/**
 * @file entry_list.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "entry_list.h"

/**
 * @brief 
 * 
 * @param list 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isEmptyEntryList(EntryList list) {
    return list == NULL;
}

/**
 * @brief 
 * 
 * @return EntryList 
 * @pre Nenhuma
 * @post Nenhuma
 */
EntryList allocEntryList() {
    return (EntryList)malloc(sizeof(Entry));
}

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
EntryList addEntryList(EntryList head, int number, char *message, CallbackFunct *funct) {
    printf("Adicionando elemento %d\n", number);
    EntryList new_node = allocEntryList();
    new_node->number = number;
    new_node->funct = funct;
    strcpy(new_node->entryMessage, message);
    if (isEmptyEntryList(head)) {
        new_node->prev = new_node->next = new_node;
        return new_node;
    }
    new_node->next = head;
    new_node->prev = head->prev;
    head->prev->next = new_node;
    head->prev = new_node;
    return head;
}

/**
 * @brief 
 * 
 * @param head 
 * @param number 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int isInLimits(EntryList head, int number) {
    return number >= 0 && number < head->prev->number;
}

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
EntryList moveEntryList(EntryList item, int qnt, int side) {
    if(side == MOVE_FOWARD) {
        while(qnt--) item = item->next;
    }else if(side == MOVE_BACKWARD) {
        while(qnt--) item = item->prev;
    }else{
        printf("Entrada invalida\n");
    }
    return item;
}

/**
 * @brief 
 * 
 * @param head 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEntryList(EntryList head) {
    EntryList p = head;
    for(; p->next != head; p = p->next) {
        printf("%d, ", p->entryMessage);
    }
    printf("%d\n", p->entryMessage);
}
