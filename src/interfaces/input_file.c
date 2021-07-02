#include "input_file.h"

void loadInputFile(char *inputPath, BTree *bTree) {
    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }
    char *line = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    while(fgets(line, MAX_ENTRY_LINE, inputFile) != NULL) {
        line = trim(line);
        formatLine(line);
        switch(line[0]) {
            case INPUT_FILE_INSERT: insertFromLine(line, bTree);
                break;
            case INPUT_FILE_MODIFY: modifyFromLine(line, bTree);
                break;
            case INPUT_FILE_REMOVE: removeFromLine(line, bTree);
                break;
        }
    }
    fclose(inputFile);
}

void insertFromLine(char *line, BTree *bTree) {
    Product *product = (Product*)malloc(sizeof(Product));
    sscanf(line, "%*c;%d;%[^;];%d;%f;%[^\n]",
        &(product->code),
        product->name,
        &(product->number),
        &(product->value),
        product->local
    );
    if(searchBTreeByCode(bTree, product->code) == -1)
        insertBTree(bTree, product);
    free(product);
}

void modifyFromLine(char *line, BTree *bTree) {
    Product *product;
    int code, position;
    char *buffer = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    sscanf(line, "%*c;%d;%[^\n]", &code, line);
    if((position = searchBTreeByCode(bTree, code)) == -1)
        return;
    product = readDataRegistry(position, bTree->dataFile);
    getFromLine(
        line,
        &product->number,
        &product->value,
        product->local
    );
    writeDataRegistry(product, position, bTree->dataFile);
    free(product);
}

void removeFromLine(char *line, BTree *bTree) {
    int code;
    sscanf(line, "%*c;%d", &code);
    removeBTree(bTree, code);
}

void getFromLine(char *line, int *number, float *value, char *local) {
    char *buffer = getInside(line);
    if (buffer[0] != '\0')
        sscanf(buffer, "%d", number);
    line += (strlen(buffer) + 1);
    free(buffer);

    buffer = getInside(line);
    if (buffer[0] != '\0')
        sscanf(buffer, "%f", value);
    line += (strlen(buffer) + 1);
    free(buffer);

    if (line[0] != '\0')
        strcpy(local, line);
}

char *getInside(char *line) {
    char *buffer = (char *)malloc(sizeof(char) * MAX_ENTRY_LINE);
    int i = 0;
    while(line[i] != ';' && line[i] != '\n' && line[i] != '\0') {
        buffer[i] = line[i];
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

void formatLine(char *line) {
    for(; *line; line++)
        if(*line == ',')
            *line = '.';
}

char *trim(char *line) {
    char *newLine = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    int i_new;
    int i_old = 0;
    while(isspace(line[i_old])) {
        i_old++;
    }
    for(i_new = 0; line[i_old]; i_old++) {
        if (!((isspace(line[i_old]) && isspace(line[i_old - 1])) ||
              (isspace(line[i_old]) && isspace(line[i_old + 1])) ||
              (line[i_old + 1] == ';' && isspace(line[i_old])) ||
              (line[i_old - 1] == ';' && isspace(line[i_old]))
        )) {
            newLine[i_new++] = line[i_old];
        }
    }
    newLine[i_new] = 0;
    free(line);
    return newLine;
}
