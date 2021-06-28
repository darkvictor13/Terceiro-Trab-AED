#include "entry_list.h"

int isEmptyEntryList(EntryList list) {
    return list == NULL;
}

EntryList allocEntryList() {
    return (EntryList)malloc(sizeof(Entry));
}

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

int isInLimits(EntryList head, int number) {
    return number >= 0 && number < head->prev->number;
}

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

void printEntryList(EntryList head) {
    EntryList p = head;
    for(; p->next != head; p = p->next) {
        printf("%d, ", p->entryMessage);
    }
    printf("%d\n", p->entryMessage);
}
