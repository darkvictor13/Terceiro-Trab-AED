#include "controllers/main_menu_controller.h"
#include "interfaces/input_file.h"
#include "models/b_tree.h"
#include "menu/arg_list.h"

int main(int argc, char *argv[]) {
    char indexFilePath[] = "./index.bin";
    char dataFilePath[] = "./data.bin";
    BTree bTree = openBTreeFiles(indexFilePath, dataFilePath);
    if(argc == 2)
        loadInputFile(argv[1], bTree);
    ArgStack argStack = createStack();
    pushArgStack(argStack, bTree);
    /// test ///
    //Product *product = (Product*)malloc(sizeof(Product));
    //for(int i = 0; i < 1000000; i++) {
    //    int randonInt = rand() % 1000000;
    //    product->code = randonInt;
    //    insertBTree(bTree, product);
    //}
    ///
    mainMenuController(argStack);
    closeBTreeFiles(bTree);
    freeArgStack(argStack);
    return 0;
}
