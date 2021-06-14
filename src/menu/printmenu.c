/**
 * @file printmenu.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar todas as formas de imprimir no Menu
 * @version 0.1
 * @date 13/06/2021
 */

#include "printmenu.h"

/**
 * @brief Imprime o cabeçalho do menu
 *
 * @param message Título do cabeçalho
 * @pre Nenhuma
 * @post Cabeçalho do menu impresso
 */
void printHead(const char *message) {
    system(CLEAR);
    printLine();
    printAlignedCenter(message);
    printLine();
}

/**
 * @brief Imprime mensagem
 * 
 * @param message ponteiro para char, informação impressa no menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printString(const char* message) {
    if(message == NULL || message[0] == '\0')
        printf("vazio");
    else
        printf("%s", message);
}

/**
 * @brief Imprime uma linha com um mensagem alinhada à direita
 *
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedLeft(const char *message) {
    printf("|%s", message);
    printExtended(' ', SIZE_LINE - strlen(message) - 2); // -2 por causa dos |
    printf("|\n");
}

/**
 * @brief Imprime uma linha com um mensagem alinhada ao meio
 * 
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
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
 * @brief Imprime uma linha com um mensagem alinhada à direita
 * 
 * @param mensagem mensagem a ser impressa
 * @pre Nenhuma
 * @post Linha impressa na tela
 */
void printAlignedRight(const char *message) {
    printf("|");
    printExtended(' ', (SIZE_LINE - (strlen(message) + 2)));
    printf("%s|\n", message);
}

/**
 * @brief Imprime uma linha separadora, preenchida com '-'
 * 
 * @pre Nenhuma
 * @post Uma única linha separadora impressa no menu
 */
void printLine() {
    printf("|");
    printExtended('-', SIZE_LINE - 2);
    printf("|\n");
}

/**
 * @brief Imprime um caractere (qnt) vezes
 * 
 * @param c caractere a ser impresso no Menu
 * @param number quantidade de vezes que o caractere deve ser impresso
 * @pre Nenhuma
 * @post Caractere impresso (qnt) vezes na tela
 */
void printExtended(char c, int number) {
    for(int i = 0; i < number; i++)
        printf("%c", c);
}

/**
 * @brief printa o menu principal
 * 
 * @param menu ponteiro para uma estrutura que contém as informações de um menu
 * @pre Nenhuma
 * @post Nenhuma
 */
void printMenu(Menu *menu) {
    menu->header();
    if(menu->queue == NULL) // verificar
        printAlignedRight("[vazia]");
    else
        printEntryQueueTail(menu->queue->head, menu->queue->tail, menu->thisOption);
    menu->footer();
}

/**
 * @brief Selecionar a opção desejada
 * 
 * @param message informação impressa no menu, resume o que a função faz
 * @param selected inteiro que define a opção selecionada ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
void printOption(const char* message, int selected) {
    printf("| [");
    if(selected)
        printf("x");
    else
        printf(" ");
    printf("] %s", message);
    printExtended(' ', SIZE_LINE - (strlen(message) + SELECT_SIZE)); // 6 caracteres antes da mensagem e 1 depois
    printf("|\n");
}

/**
 * @brief Printa todas as opçoes 
 * 
 * @param start ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param end ponteiro para uma estrutura que contém as informações do nó de entrada 
 * @param i inteiro utilizado para passar pela fila
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEntryQueueTail(EntryNode *start, EntryNode *end, int i) {
    printOption(start->entryMessage, 0 == i);
    if (start != end)
        printEntryQueueTail(start->prox, end, --i);
}

/**
 * @brief Imprime um menu para pausar o programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
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
 * @brief Imprime a mensagem que indica o encerramento do programa
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printEndMessage() {
    system(CLEAR);
    printLine();
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printAlignedCenter("Programa finalizado com sucesso");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printf("|%*s|\n", SIZE_LINE - 2, "");
    printLine();
}