#include "main_menu_controller.h"

void mainMenuHeader() {
    printLine();
    printAlignedCenter("Principal");
    printLine();
}

void mainMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int mainMenuController(ArgStack head) {
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

int actionInsert(ArgStack head) {
    Product *product = scanProduct();
    insertBTree(readArgStack(head), product);
    free(product);
    printWaitMenu();
    return 1;
}

int actionSearch(ArgStack head) {
    searchMenuController(head);
    return 1;
}

int actionChange(ArgStack head) {
    changeMenuController(head);
    return 1;
}

int actionLoad(ArgStack head) {
    char inputPath[FILE_PATH_NAME];
    printf("\n\tNome de arquivo de entrada: ");
    scanf("%s%*c", inputPath);
    printf("\n");
    loadInputFile(inputPath, readArgStack(head));
    return 1;
}

int actionRemove(ArgStack head) {
    int code;
    printf("\n\tCodigo do produto: ");
    scanf("%d%*c", &code);
    printf("\n");
    confirmMenuController(head);
    if(popArgStack(head)) {
        if(removeBTree(readArgStack(head), code))
            printWaitMenuWhitMessage("Produto removido com sucesso.");
        else
            printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    return 1;
}

int actionClose(ArgStack head) {
    printEndMessage();
    return 0;
}
