/**
 * @file interfacemenu.h
 * @author Victor Emanuel Almeida
 * @brief Arquivo responsável por definir todas as funções
 * que o usuário que utiliza o menu poderá chamar
 * @version 0.1
 * @date 14/06/2021
 */

#include "interfacemenu.h"

/**
 * @brief Remove um dos itens do menu
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila reduzido
 */
int removeEntryQueue(EntryQueue *queue) {
    EntryNode *head = queue->head;
    if (head == queue->tail)
        queue->tail = NULL;
    queue->tail = queue->tail->prox;
    free(head);
    return --queue->size;
}

/**
 * @brief Insere um novo elemento na fila
 * 
 * @param queue ponteiro para uma estrutura que contém as 
 * informações de uma fila
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertEntryQueue(EntryQueue *queue, char *message, CallbackFunct *funct) {
    EntryNode *newTail = allocEntryNode();
    newTail->funct = funct;
    strcpy(newTail->entryMessage, message);
    newTail->prox = NULL;
    if (emptyEntryQueue(queue))
        queue->head = newTail;
    else
        queue->tail->prox = newTail;
    queue->size++;
    queue->tail = newTail;
}

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Menu criado
 */
Menu *createMenu() {
    Menu* menu = (Menu *)malloc(sizeof(Menu));
    menu->options = menu->thisOption = 0;
    menu->queue = createEntryQueue();
    return menu;
}

/**
 * @brief Adiciona mais uma opção ao menu passado por parâmetro
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Menu carregado
 * @post Mais uma função ao menu
 */
void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct) {
    menu->options++;
    insertEntryQueue(menu->queue, message, funct);
}

/**
 * @brief  the Header object
 * 
 * @param menu 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param header 
 * @pre Menu carregado
 * @post 
 */
void setHeader(Menu *menu, HeaderFunct header) {
    menu->header = header;
}

void setFooter(Menu *menu, FooterFunct footer) {
    menu->footer = footer;
}