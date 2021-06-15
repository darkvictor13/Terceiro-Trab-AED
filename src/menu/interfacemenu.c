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
int removeEntryQueue(List *queue) {
    return 1;
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
    menu->first = menu->selected = NULL;
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
    int number;
    if (isEmptyList(menu->first)){
        number = 1;
    }else{
        number = menu->first->prev->number + 1;
    }

    menu->first = insertAtEnd(menu->first, number, message, funct);

    // se foi a primeira inserção
    if (number == 1) {
        menu->selected = menu->first;
    }
}

/**
 * @brief Conecta um menu a seu header
 * 
 * @param menu 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param header ponteiro para função de header
 * @pre Menu carregado
 * @post Menu possui um header
 */
void setHeader(Menu *menu, HeaderFunct header) {
    menu->header = header;
}

/**
 * @brief Conecta um menu a seu footer
 * 
 * @param menu 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param footer ponteiro para função de footer
 * @pre Menu carregado
 * @post Menu possui um footer
 */
void setFooter(Menu *menu, FooterFunct footer) {
    menu->footer = footer;
}
