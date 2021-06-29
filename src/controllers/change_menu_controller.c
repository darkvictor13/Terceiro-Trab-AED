#include "change_menu_controller.h"

void changeMenuHeader() {
    printLine();
    printAlignedCenter("");
    printLine();
}

void changeMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int changeMenuController(ArgList head) {
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

int actionChangeNumber(ArgList head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchBTreeByCode(head->arg, code)) != -1) {
        Product *product = getBTreeProduct(head->arg, position);
        printf("\tIndique o numero de produtos em estoque: ");
        scanf("%d%*c", &(product->number));
        //if(confirm())
            //updateProduct(((BTree*)head->arg)->dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

int actionChangeValue(ArgList head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d", &code);
    if((position = searchBTreeByCode(head->arg, code)) != -1) {
        Product *product = getBTreeProduct(head->arg, position);
        printf("Indique o novo valor do produto: ");
        scanf("%f%*c", &(product->value));
        //if(confirm())
            //updateProduct(dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

int actionChangeLocal(ArgList head) {
    int code, position;
    printf("\tIndique o codigo do produto: ");
    scanf("%d%*c", &code);
    if((position = searchBTreeByCode(head->arg, code)) != -1) {
        Product *product = getBTreeProduct(head->arg, position);
        printf("Indique o novo local do produto: ");
        scanf("%[^\n]%*c", product->local);
        //if(confirm())
            //updateProduct(dataFile, position, product);
        free(product);
    }else{
        printf("Produto nao encontrado.\n");
    }
    printWaitMenu();
    return 1;
}

int actionChangeReturn(ArgList head) {
    return 0;
}
