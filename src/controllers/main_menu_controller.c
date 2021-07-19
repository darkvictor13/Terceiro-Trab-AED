/**
 * @file main_menu_controller.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main_menu_controller.h"

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuHeader() {
    printLine();
    printAlignedCenter("Principal");
    printLine();
}

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void mainMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int mainMenuController(ArgStack head) {
    Menu *mainMenu = createMenu();
    setHeader(mainMenu, mainMenuHeader);
    setFooter(mainMenu, mainMenuFooter);
    addEntryToMenu(mainMenu, "Inserir produto.", actionInsert);
    addEntryToMenu(mainMenu, "Buscar produto.", actionSearch);
    addEntryToMenu(mainMenu, "Mudar dados do produto.", actionChange);
    addEntryToMenu(mainMenu, "Carregar lista de produtos.", actionLoad);
    addEntryToMenu(mainMenu, "Remover produto.", actionRemove);
    addEntryToMenu(mainMenu, "Fechar programa.", actionClose);
    controlMenu(mainMenu, head);
    return 1;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionInsert(ArgStack head) {
    Product *product = scanProduct();
    insertBTree(readArgStack(head), product);
    free(product);
    printWaitMenu();
    return 1;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearch(ArgStack head) {
    searchMenuController(head);
    return 1;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChange(ArgStack head) {
    changeMenuController(head);
    return 1;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionLoad(ArgStack head) {
    char inputPath[FILE_PATH_NAME];
    printf("\n\tNome de arquivo de entrada: ");
    scanf("%s%*c", inputPath);
    printf("\n");
    loadInputFile(inputPath, readArgStack(head));
    return 1;
}

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
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

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionClose(ArgStack head) {
    printEndMessage();
    return 0;
}
