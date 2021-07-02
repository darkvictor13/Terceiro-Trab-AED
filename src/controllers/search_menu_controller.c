#include "search_menu_controller.h"

void searchMenuHeader() {
    printLine();
    printAlignedCenter("Menu de busca");
    printLine();
}

void searchMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int searchMenuController(ArgStack head) {
    Menu *searchMenu = createMenu();
    setHeader(searchMenu, searchMenuHeader);
    setFooter(searchMenu, searchMenuFooter);
    addEntryToMenu(searchMenu, "Buscar produto por codigo.", actionSearchProductByCode);
    addEntryToMenu(searchMenu, "Listar produtos.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore.", actionPrintTree);
    addEntryToMenu(searchMenu, "Mostrar espacos livres.", actionPrintFreeSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    controlMenu(searchMenu, head);
    return 1;
}

int actionSearchProductByCode(ArgStack head) {
    int code, position;
    printf("\tInsira o codigo do produto: ");
    scanf("%d%*c", &code);
    if((position = searchBTreeByCode(readArgStack(head), code)) != -1) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printProduct(product);
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

int actionListProducts(ArgStack head) {
    printHead("Imprimindo a Arvore em ordem crescente");
    printBTreeInOrder(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionPrintTree(ArgStack head) {
    printHead("Imprimindo a Arvore em niveis");
    printBTreeByLevel(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionPrintFreeSpaces(ArgStack head) {
    printHead("Espacos livres");
    printBTreeFree(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionSearchReturn(ArgStack head) {
    return 0;
}
