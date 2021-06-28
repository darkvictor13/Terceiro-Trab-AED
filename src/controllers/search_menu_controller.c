#include "search_menu_controller.h"

void searchMenuHeader() {
    printLine();
    printAlignedCenter("");
    printLine();
}

void searchMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int searchMenuController(ArgList head) {
    Menu *searchMenu = createMenu();
    setHeader(searchMenu, searchMenuHeader);
    setFooter(searchMenu, searchMenuFooter);
    //addEntryToMenu(searchMenu, "Buscar produto por nome.", actionSearchProductByName);
    addEntryToMenu(searchMenu, "Buscar produto por codigo.", actionSearchProductByCode);
    addEntryToMenu(searchMenu, "Listar produtos.", actionListProducts);
    addEntryToMenu(searchMenu, "Mostrar arvore.", actionPrintTree);
    addEntryToMenu(searchMenu, "Mostrar espacos livres.", actionPrintFreeSpaces);
    addEntryToMenu(searchMenu, "Voltar.", actionSearchReturn);
    controlMenu(searchMenu, head);
    return 1;
}

int actionSearchProductByName(ArgList head) {
    /*char name[MAX_NAME];
    printf("Insira o nome do produto: ");
    scanf("%[^\n]%*c", name);
    searchProductByName(dataFile, name);*/
    printWaitMenu();
    return 1;
}

int actionSearchProductByCode(ArgList head) {
    /*int code, position;
    printf("\tInsira o codigo do produto: ");
    scanf("%d%*c", &code);
    if((position = searchProductByCode(dataFile, code)) != -1) {
        Product *product = readNodeProduct(dataFile, position);
        printProduct(product);
        free(product);
    }*/
    printWaitMenu();
    return 1;
}

int actionListProducts(ArgList head) {
    /*printHead("Imprimindo a Arvore em ordem crescente");
    printInOrder(dataFile);*/
    printWaitMenu();
    return 1;
}

int actionPrintTree(ArgList head) {
    /*printHead("Imprimindo a Arvore em niveis");
    printByLevel(dataFile);*/
    printWaitMenu();
    return 1;
}

int actionPrintFreeSpaces(ArgList head) {
    /*printHead("Espacos livres");
    printFree(dataFile);*/
    printWaitMenu();
    return 1;
}

int actionSearchReturn(ArgList head) {
    return 0;
}
