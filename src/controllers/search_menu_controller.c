/**
 * @file search_menu_controller.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "search_menu_controller.h"

/**
 * @brief imprime o cabecalho do menu de busca
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuHeader() {
    printLine();
    printAlignedCenter("Menu de busca");
    printLine();
}

/**
 * @brief imprime o rodape do menu de busca
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

/**
 * @brief cria o menu de busca e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchMenuController(ArgStack head) {
    Menu *searchMenu = createMenu();
    setHeader(searchMenu, searchMenuHeader);
    setFooter(searchMenu, searchMenuFooter);
    addEntryToMenu(searchMenu, "Buscar produto por codigo.", actionSearchProductByCode);
    addEntryToMenu(searchMenu, "Listar produtos em ordem.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore por niveis.", actionPrintTree);
    addEntryToMenu(searchMenu, "Lista de registros em arquivo.", actionPrintRegistryList);
    addEntryToMenu(searchMenu, "Lista de produtos em arquivo.", actionPrintProductList);
    addEntryToMenu(searchMenu, "Mostrar espacos livres em arvore.", actionPrintFreeIndexSpaces);
    addEntryToMenu(searchMenu, "Mostrar espacos livres em produtos.", actionPrintFreeDataSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    controlMenu(searchMenu, head);
    return 1;
}

/**
 * @brief entrada do menu principal para realizar a busca de um produto por codigo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchProductByCode(ArgStack head) {
    int code, position;
    printf("\n\tInsira o codigo do produto: ");
    scanf("%d%*c", &code);
    printf("\n");
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printProduct(product);
        printWaitMenu();
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

/**
 * @brief entrada do menu principal para listar os produtos em ordem crescente
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionListProducts(ArgStack head) {
    printHead("Imprimindo a Arvore em ordem crescente.");
    printf("\n");
    printBTreeInOrder(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para imprimir a arvore b por niveis
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintTree(ArgStack head) {
    printHead("Imprimindo a Arvore em niveis.");
    printBTreeByLevel(readArgStack(head));
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para imprimir os dados contidos no arquivo que representa a arvore b
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintRegistryList(ArgStack head) {
    printHead("Imprimindo lista de registros.");
    printBTreeRegistryList(readArgStack(head));
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para imprimir os dados contidos no arquivo de dados
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintProductList(ArgStack head) {
    printHead("Imprimindo lista de produtos.");
    printBTreeProductList(readArgStack(head));
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para imprimir a lista de espacos livres no arquivo que representa a arvore b
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeIndexSpaces(ArgStack head) {
    printHead("Listas de registros livres no arquivo da arvore.");
    printf("\n");
    printBTreeFreeIndex(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para imprimir a lista de espacos livres no arquivo de dados de produtos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeDataSpaces(ArgStack head) {
    printHead("Listas de registros livres no arquivo de produtos.");
    printf("\n");
    printBTreeFreeData(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

/**
 * @brief entrada do menu principal para retornar ao menu anterior
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchReturn(ArgStack head) {
    return 0;
}
