/**
 * @file confirm_menu_controller.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "confirm_menu_controller.h"

/**
 * @brief imprime o cabecalho do menu de confirmacao
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void confirmMenuHeader() {
    printLine();
    printAlignedCenter("Desea realmente realizar esa acao?");
    printLine();
}

/**
 * @brief imprime o rodape do menu de confirmacao
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void confirmMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

/**
 * @brief cria o menu de confirmacao e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int confirmMenuController(ArgStack head) {
    Menu *confirmMenu = createMenu();
    setHeader(confirmMenu, confirmMenuHeader);
    setFooter(confirmMenu, confirmMenuFooter);
    addEntryToMenu(confirmMenu, "Sim.", actionConfirmYes);
    addEntryToMenu(confirmMenu, "No.", actionConfirmNo);
    controlMenu(confirmMenu, head);
    return 0;
}

/**
 * @brief entrada do menu para confirmar o que esta sendo requerido
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionConfirmYes(ArgStack head) {
    pushArgStack(head, (void*)1);
    return 0;
}

/**
 * @brief entrada do menu para confirmar o que esta sendo requerido
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionConfirmNo(ArgStack head) {
    pushArgStack(head, (void*)0);
    return 0;
}
