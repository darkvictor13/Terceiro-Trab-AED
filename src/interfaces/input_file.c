#include "input_file.h"

void loadInputFile(char *inputPath, FILE *dataFile) {
    /*FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("Arquivo nao encontrado.\n");
        return;
    }
    char *line = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    while(fgets(line, MAX_ENTRY_LINE, inputFile) != NULL) {
        line = trim(line);
        formatLine(line);
        switch(line[0]) {
            case INPUT_FILE_INSERT: insertFornLine(line, dataFile);
                break;
            case INPUT_FILE_MODIFY: modifyFornLine(line, dataFile);
                break;
            case INPUT_FILE_REMOVE: removeFromLine(line, dataFile);
                break;
        }
    }
    fclose(inputFile);*/
}

void formatLine(char *line) {
    /*for(; *line; line++)
        if(*line == ',')
            *line = '.';*/
}

void insertFornLine(char *line, FILE *dataFile) {
    /*Product *product = (Product*)malloc(sizeof(Product));
    sscanf(line, "%*c;%d;%[^;];%d;%f;%[^\n]",
        &(product->code),
        product->name,
        &(product->number),
        &(product->value),
        product->local
    );
    if(searchProductByCode(dataFile, product->code) == -1)
        insertProduct(dataFile, product);
    free(product);*/
}

void modifyFornLine(char *line, FILE *dataFile) {
    /*Node *node;
    int code, position;
    char *buffer = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
    sscanf(line, "%*c;%d;%[^\n]", &code, line);
    if((position = searchProductByCode(dataFile, code)) == -1)
        return;
    node = readNode(dataFile, position);
    getFromLine(
        line,
        &node->product.number,
        &node->product.value,
        node->product.local
    );
    writeNode(dataFile, node, position);
    free(node);*/
}

void getFromLine(char *line, int *number, float *value, char *local) {
    /*char *buffer = getInside(line);
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
        strcpy(local, line);*/
}

char *getInside(char *line) {
    /*char *buffer = (char *)malloc(sizeof(char) * MAX_ENTRY_LINE);
    int i = 0;
    while(line[i] != ';' && line[i] != '\n' && line[i] != '\0') {
        buffer[i] = line[i];
        i++;
    }
    buffer[i] = '\0';
    return buffer;*/
}

void removeFromLine(char *line, FILE *dataFile) {
    /*int code;
    sscanf(line, "%*c;%d", &code);
    removeProduct(dataFile, code);*/
}

char *trim(char *line) {
    /*char *newLine = (char*)malloc(sizeof(char)*MAX_ENTRY_LINE);
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
    return newLine;*/
}
