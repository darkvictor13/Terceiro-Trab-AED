#include "controllers/main_menu_controller.h"
#include "interfaces/input_file.h"
#include "models/b_tree.h"
#include "menu/arg_list.h"

int main(int argc, char *argv[]) {
    char indexFilePath[] = "./index.bin";
    char dataFilePath[] = "./data.bin";
    BTree *bTree = openBTreeFiles(indexFilePath, dataFilePath);
    //if(argc == 2)
    //    loadInputFile(argv[1], bTree);
    ArgList argList = addArgList(NULL, bTree);
    mainMenuController(argList);
    closeBTreeFiles(bTree);
    freeArgList(argList);
    return 0;
}
