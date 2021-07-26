/**
 * @file change_menu_controller.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "change_menu_controller.h"

/**
 * @brief imprime o cabecalho do menu de alteracoes
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuHeader() {
    printLine();
    printAlignedCenter("Menu de alteracoes");
    printLine();
}

/**
 * @brief imprime o rodape do menu de alteracoes
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

/**
 * @brief cria um menu de alteracoes e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int changeMenuController(ArgStack head) {
    Menu *changeMenu = createMenu();
    setHeader(changeMenu, changeMenuHeader);
    setFooter(changeMenu, changeMenuFooter);
    addEntryToMenu(changeMenu, "Alterar quantidade em estoque.", actionChangeNumber);
    addEntryToMenu(changeMenu, "Alterar preco.", actionChangeValue);
    addEntryToMenu(changeMenu, "Alterar localizacao.", actionChangeLocal);
    addEntryToMenu(changeMenu, "Voltar.", actionChangeReturn);
    controlMenu(changeMenu, head);
    return 1;
}

/**
 * @brief entrada do menu de alteracoes para alterar o numero de elementos em estoque
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeNumber(ArgStack head) {
    int code, position;
    printf("\n\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    printf("\n");
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("\tIndique o numero de produtos em estoque: ");
        scanf("%d%*c", &(product->number));
        printf("\n");
        confirmMenuController(head);
        if(popArgStack(head)) {
            updateBTreeProduct(readArgStack(head), position, product);
            printWaitMenuWhitMessage("Mudanca realizada com sucesso.");
        }
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

/**
 * @brief entrada do menu de alteracoes para alterar o valor do elemento em estoque
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeValue(ArgStack head) {
    int code, position;
    printf("\n\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    printf("\n");
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("\tIndique o novo valor do produto: ");
        scanf("%f%*c", &(product->value));
        printf("\n");
        confirmMenuController(head);
        if(popArgStack(head)) {
            updateBTreeProduct(readArgStack(head), position, product);
            printWaitMenuWhitMessage("Mudanca realizada com sucesso.");
        }
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

/**
 * @brief entrada do menu de alteracoes para alterar o local onde sen encontra o produtos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeLocal(ArgStack head) {
    int code, position;
    printf("\n\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    printf("\n");
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("\tIndique o novo local do produto: ");
        scanf("%[^\n]%*c", product->local);
        printf("\n");
        confirmMenuController(head);
        if(popArgStack(head)) {
            updateBTreeProduct(readArgStack(head), position, product);
            printWaitMenuWhitMessage("Mudanca realizada com sucesso.");
        }
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

/**
 * @brief entradda do menu de alteracoes para voltar ao menu anterior
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeReturn(ArgStack head) {
    return 0;
}
