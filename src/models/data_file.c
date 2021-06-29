#include "data_file.h"

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