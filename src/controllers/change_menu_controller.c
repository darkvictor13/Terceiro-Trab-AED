#include "change_menu_controller.h"

void changeMenuHeader() {
    printLine();
    printAlignedCenter("Menu de alteracoes");
    printLine();
}

void changeMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int changeMenuController(ArgStack head) {
    Menu *changeMenu = createMenu();
    setHeader(changeMenu, changeMenuHeader);
    setFooter(changeMenu, changeMenuFooter);
    addEntryToMenu(changeMenu, "Alterar estoque.", actionChangeNumber);
    addEntryToMenu(changeMenu, "Alterar preco.", actionChangeValue);
    addEntryToMenu(changeMenu, "Alterar localizacao.", actionChangeLocal);
    addEntryToMenu(changeMenu, "Voltar.", actionChangeReturn);
    controlMenu(changeMenu, head);
    return 1;
}

int actionChangeNumber(ArgStack head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("\tIndique o numero de produtos em estoque: ");
        scanf("%d%*c", &(product->number));
        confirmMenuController(head);
        if(popArgStack(head)) {
            updateBTreeProduct(readArgStack(head), position, product);
            printWaitMenuWhitMessage("Mudanca realizada com sucesso.");
        }
        free(product);
    }else{
        printWaitMenuWhitMessage("Produto nao encontrado.");
    }
    printWaitMenu();
    return 1;
}

int actionChangeValue(ArgStack head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("Indique o novo valor do produto: ");
        scanf("%f%*c", &(product->value));
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

int actionChangeLocal(ArgStack head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    if(searchBTreeByCode(readArgStack(head), code, &position)) {
        Product *product = getBTreeProduct(readArgStack(head), position);
        printf("Indique o novo local do produto: ");
        scanf("%[^\n]%*c", product->local);
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

int actionChangeReturn(ArgStack head) {
    return 0;
}
