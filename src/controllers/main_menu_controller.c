#include "main_menu_controller.h"

void mainMenuHeader() {
    printLine();
    printAlignedCenter("Principal");
    printLine();
}

void mainMenuFooter() {
    printLine();
    printAlignedRight("fim");
    printLine();
}

int mainMenuController(ArgList head) {
    Menu *mainMenu = createMenu();
    setHeader(mainMenu, mainMenuHeader);
    setFooter(mainMenu, mainMenuFooter);
    addEntryToMenu(mainMenu, "Inserir produto.", actionInsert);
    addEntryToMenu(mainMenu, "Buscar produto.", actionSearch);
    addEntryToMenu(mainMenu, "Cambiar informacao de produto.", actionChange);
    addEntryToMenu(mainMenu, "Carregar lista de produtos.", actionLoad);
    addEntryToMenu(mainMenu, "Remover produto.", actionRemove);
    addEntryToMenu(mainMenu, "Fechar programa.", actionClose);
    controlMenu(mainMenu, head);
    return 1;
}

int actionInsert(ArgList head) {
    Product *product = scanProduct();
    insertBTree(head->arg, product);
    free(product);
    printWaitMenu();
    return 1;
}

int actionSearch(ArgList head) {
    searchMenuController(head);
    return 1;
}

int actionChange(ArgList head) {
    changeMenuController(head);
    return 1;
}

int actionLoad(ArgList head) {
    char inputPath[FILE_PATH_NAME];
    printf("\tNome de arquivo de entrada: ");
    scanf("%s", inputPath);
    loadInputFile(inputPath, head->arg);
    printWaitMenu();
    return 1;
}

int actionRemove(ArgList head) {
    int code;
    printf("\tCodigo do produto: ");
    scanf("%d%*c", &code);
    if(removeBTree(head->arg, code) != -1)
        printf("Produto removido com sucesso.\n");
    else
        printf("Produto nao encontrado.\n");
    printWaitMenu();
    return 1;
}

int actionClose(ArgList head) {
    printEndMessage();
    return 0;
}
