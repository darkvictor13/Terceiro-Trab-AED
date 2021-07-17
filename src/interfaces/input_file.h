#ifndef INPUT_FILE_H
#define INPUT_FILE_H

#include <ctype.h>
#include <stdio.h>
#include "../models/b_tree.h"
#include "../models/product.h"
#include "../menu/print_menu.h"

#define FILE_PATH_NAME 100

enum inputFileOperations {
    INPUT_FILE_INSERT = 'I',
    INPUT_FILE_MODIFY = 'A',
    INPUT_FILE_REMOVE = 'R',
};

void loadInputFile(char *inputPath, BTree bTree);

void insertFromLine(char *line, BTree bTree);

void modifyFromLine(char *line, BTree bTree);

void removeFromLine(char *line, BTree bTree);

void getFromLine(char *line, int *number, float *value, char *local);

char *getInside(char *line);

void formatLine(char *line);

char *trim(char *line);

#endif
