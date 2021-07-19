/**
 * @file print_menu.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "print_menu.h"

void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

void printString(const char* message) {
    if(message == NULL || message[0] == '\0')
        printf("vazio");
    else
        printf("%s", message);
}

void printAlignedLeft(const char *message) {
    printf("|%s", message);
    printExtended(' ', SIZE_LINE - (strlen(message) + 2));
    printf("|\n");
}

void printAlignedCenter(const char *message) {
    int sizeRead = (strlen(message) + 2);
    int space = (SIZE_LINE - sizeRead) / 2;
    printf("|");
    printExtended(' ', space);
    printf("%s", message);
    printExtended(' ', space);
    if (!(sizeRead % 2))
        printf(" ");
    printf("|\n");
}

void printAlignedRight(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

void printExtended(char c, int number) {
    for(int i = 0; i < number; i++)
        putchar(c);
}

void printMenu(Menu *menu) {
    menu->header();
    if(isEmptyEntryList(menu->first))
        printAlignedCenter("Menu não possui opções");
    else {
        printListOptions(menu->first, menu->selected);
    }
    menu->footer();
}

void printListOptions(EntryList first, EntryList selected) {
    EntryList p = first;
    for (; p->next != first; p = p->next) {
        printOption(p, p == selected);
    }
    printOption(p, p == selected);
}

void printOption(EntryList item, int selected) {
    putchar('|');
    if(selected)
        printf(" ->");
    else
        printf("   ");
    printf("%2d - %s", item->number, item->entryMessage);
    printExtended(' ', SIZE_LINE - (strlen(item->entryMessage) + SELECT_SIZE)); // 6 caracteres antes da mensagem e 1 depois
    printf("|\n");
}

void printWaitMenu() {
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Pressione [Enter] para continuar");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
    getchar();
}

void printWaitMenuWhitMessage(const char *message) {
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter(message);
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Pressione [Enter] para continuar.");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
    getchar();
}

void printEndMessage() {
    system(CLEAR);
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Programa finalizado com sucesso.");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
}