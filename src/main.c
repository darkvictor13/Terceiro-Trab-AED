/**
 * @file main.c
 * @author Victor Emanuel Almeida
 * @brief 
 * @version 0.1
 * @date 24/06/2021
 */

#include "controllers/main_menu_controller.h"

int main(int argc, char *argv[]) {
    char filePath[] = "./data.bin";
    FILE *dataFile = fopen(filePath, "r+b");
    if(dataFile == NULL) {
        //dataFile = makeDataFile(filePath);
    }else{
        //setbuf(dataFile, NULL);
    }
    if(argc == 2) {
        //loadInputFile(argv[1], dataFile);
    }
    mainMenuController(dataFile);
    //fclose(dataFile);
    return 0;
}
