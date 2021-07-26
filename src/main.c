/**
 * @file main.c
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "controllers/main_menu_controller.h"
#include "interfaces/input_file.h"
#include "models/b_tree.h"
#include "menu/arg_list.h"

/**
 * @brief funcao principal do programa
 * 
 * @param argc numero de argumentos
 * @param argv vetor de argumentos
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int main(int argc, char *argv[]) {
    char indexFilePath[] = "./index.bin";
    char dataFilePath[] = "./data.bin";
    BTree bTree = openBTreeFiles(indexFilePath, dataFilePath);
    if(argc == 2)
        loadInputFile(argv[1], bTree);
    ArgStack argStack = createStack();
    pushArgStack(argStack, bTree);
    mainMenuController(argStack);
    closeBTreeFiles(bTree);
    freeArgStack(argStack);
    return 0;
}
