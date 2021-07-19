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
    addEntryToMenu(searchMenu, "Listar produtos em orden.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore por niveis.", actionPrintTree);
    addEntryToMenu(searchMenu, "Lista de registros em arquivo.", actionPrintRegistryList);
    addEntryToMenu(searchMenu, "Lista de produtos em arquivo.", actionPrintProductList);
    addEntryToMenu(searchMenu, "Mostrar espacos livres em arvore.", actionPrintFreeIndexSpaces);
    addEntryToMenu(searchMenu, "Mostrar espacos livres em produtos.", actionPrintFreeDataSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    controlMenu(searchMenu, head);
    return 1;
}

int actionSearchProductByCode(ArgStack head) {
    int code, position;
    printf("\tInsira o codigo do produto: ");
    scanf("%d%*c", &code);
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

int actionListProducts(ArgStack head) {
    printHead("Imprimindo a Arvore em ordem crescente.");
    printf("\n");
    printBTreeInOrder(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

int actionPrintTree(ArgStack head) {
    printHead("Imprimindo a Arvore em niveis.");
    printBTreeByLevel(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionPrintRegistryList(ArgStack head) {
    printHead("Imprimindo lista de registros.");
    printBTreeRegistryList(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionPrintProductList(ArgStack head) {
    printHead("Imprimindo lista de produtos.");
    printBTreeProductList(readArgStack(head));
    printWaitMenu();
    return 1;
}

int actionPrintFreeIndexSpaces(ArgStack head) {
    printHead("Listas de registros livres no arquivo da arvore.");
    printf("\n");
    printBTreeFreeIndex(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

int actionPrintFreeDataSpaces(ArgStack head) {
    printHead("Listas de registros livres no arquivo de produtos.");
    printf("\n");
    printBTreeFreeData(readArgStack(head));
    printf("\n\n");
    printWaitMenu();
    return 1;
}

int actionSearchReturn(ArgStack head) {
    return 0;
}
