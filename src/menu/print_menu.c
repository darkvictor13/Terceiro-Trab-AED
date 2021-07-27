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

/**
 * @brief Função padrão para imprimir o cabeçalho
 * do menu
 * 
 * @param message Mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

/**
 * @brief Imprime uma string na tela
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printString(const char* message) {
    if(message == NULL || message[0] == '\0')
        printf("vazio");
    else
        printf("%s", message);
}

/**
 * @brief Imprime a mensagem alinhada a Esquerda
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printAlignedLeft(const char *message) {
    printf("|%s", message);
    printExtended(' ', SIZE_LINE - (strlen(message) + 2));
    printf("|\n");
}

/**
 * @brief Imprime a mensagem alinhada ao centro do console
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
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

/**
 * @brief Imprime a mensagem alinhada a direita
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printAlignedRight(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

/**
 * @brief Imprime uma linha do Menu
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

/**
 * @brief Imprime um caractere "number" vezes
 * 
 * @param c caractere a ser impresso
 * @param number quantidade de vezes a ser impresso
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printExtended(char c, int number) {
    for(int i = 0; i < number; i++)
        putchar(c);
}

/**
 * @brief Imprime o menu completo
 * 
 * @param menu 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printMenu(Menu *menu) {
    menu->header();
    if(isEmptyEntryList(menu->first))
        printAlignedCenter("Menu não possui opções");
    else {
        printListOptions(menu->first, menu->selected);
    }
    menu->footer();
}

/**
 * @brief Imprime A lista de opções do menu
 * 
 * @param first primeira opção do menu
 * @param selected opção selecionada do menu
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
void printListOptions(EntryList first, EntryList selected) {
    EntryList p = first;
    for (; p->next != first; p = p->next) {
        printOption(p, p == selected);
    }
    printOption(p, p == selected);
}

/**
 * @brief Imprime uma única opção do menu
 * 
 * @param item o item do menu
 * @param selected boleano se ele está selecionado
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
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

/**
 * @brief Imprime um menu que aguarda a entrada do usuário para continuar
 * equivalente ao system(PAUSE) porém multi-plataforma
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
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

/**
 * @brief Imprime um menu que aguarda a entrada do usuário para continuar
 * porém com uma mensagem extra passada como parâmetro
 * 
 * @param message mensagem a ser impressa
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
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

/**
 * @brief Imprime a mensagem final do programa
 * 
 * @pre Nenhuma
 * @post Elemento impresso na tela
 */
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