#include "data_file.h"

FILE *makeDataFile(char *dataFilePath) {
    FILE *dataFile = fopen(dataFilePath, "w+b");
    DataHead head;
    head.regLast = 0;
    head.regFree = -1;
    writeDataHead(&head, dataFile);
    return dataFile;
}

void writeDataHead(DataHead *head, FILE *dataFile) {
    fseek(dataFile, OFFSET_HEAD_DATA, SEEK_SET);
    fwrite(head, sizeof(DataHead), 1, dataFile);
}

DataHead *readDataHead(FILE *dataFile) {
    DataHead *head = (DataHead*)malloc(sizeof(DataHead));
    fseek(dataFile, OFFSET_HEAD_DATA, SEEK_SET);
    fread(head, sizeof(DataHead), 1, dataFile);
    return head;
}

void writeDataHeadField(int value, int offset, FILE *dataFile) {
    fseek(dataFile, offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

int readDataHeadField(int offset, FILE *dataFile) {
    int value;
    fseek(dataFile, offset, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

void writeDataRegistry(Product *product, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position, SEEK_SET);
    fwrite(product, sizeof(Product), 1, dataFile);
}

Product *readDataRegistry(int position, FILE *dataFile) {
    Product *product = (Product*)malloc(sizeof(Product));
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position, SEEK_SET);
    fread(product, sizeof(Product), 1, dataFile);
    return product;
}

void writeDataRegistryField(int value, int offset, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position + offset, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

int readDataRegistryField(int offset, int position, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(DataHead) + sizeof(Product) * position + offset, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

void clearDataRegistry(int position, FILE *dataFile) {
    Product *product = (Product*)malloc(sizeof(Product));
    memset(product, 0, sizeof(Product));
    writeDataRegistry(product, position, dataFile);
}

int insertDataRegistry(Product *product, FILE *dataFile) {
    int free = readDataHeadField(OFFSET_FREE_DATA, dataFile);
    if(free == -1) {
        int last;
        writeDataRegistry(
            product,
            (last = readDataHeadField(OFFSET_LAST_DATA, dataFile)),
            dataFile
        );
        writeDataHeadField(last + 1, OFFSET_LAST_DATA, dataFile);
        return last;
    }else{
        writeDataHeadField(
            readDataRegistryField(OFFSET_PRODUCT_CODE, free, dataFile),
            OFFSET_FREE_DATA,
            dataFile
        );
        writeDataRegistry(product, free, dataFile);
        return free;
    }
}

void removeDataRegistry(int position, FILE *dataFile) {
    clearDataRegistry(position, dataFile);
    writeDataRegistryField(
        readDataHeadField(
            OFFSET_FREE_DATA,
            dataFile
        ),
        OFFSET_PRODUCT_CODE,
        position,
        dataFile
    );
    writeDataHeadField(position, OFFSET_FREE_DATA, dataFile);
}
