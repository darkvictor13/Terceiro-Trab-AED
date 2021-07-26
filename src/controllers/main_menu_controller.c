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
 * @brief imprime o cabecalho do menu principal
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
 * @brief imprime o rodape do menu principal
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
 * @brief cria o menu principal e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
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
 * @brief entrada do menu principal para acessar ao menu de insercao
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
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
 * @brief entrada do menu principal para acessar ao menu de busca
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearch(ArgStack head) {
    searchMenuController(head);
    return 1;
}

/**
 * @brief entrada do menu principal para acessar ao menu de alteracoes
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChange(ArgStack head) {
    changeMenuController(head);
    return 1;
}

/**
 * @brief entrada do menu principal para carregar um arquivo de dados de entrada
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
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
 * @brief entrada do menu principal para remover um elemento da arvore de elementos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
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
 * @brief entrada do menu principal para encerrar o programa
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionClose(ArgStack head) {
    printEndMessage();
    return 0;
}
