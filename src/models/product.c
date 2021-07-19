#include "product.h"

Product *allocProduct() {
    Product *product = (Product *)malloc(sizeof(Product));
    product->code = 0;
    reset(product->name, MAX_NAME);
    product->number = 0;
    product->value = 0;
    reset(product->local, MAX_LOCAL);
    return product;
}

void printProduct(Product *product) {
    printLine();
    printf("\n\tNome: ");
    printString(product->name);
    printf(".\n\tCode: %d.\n", product->code);
    printf("\tNumber: %d.\n", product->number);
    printf("\tValue: %.2f.\n", product->value);
    printf("\tLocal: ");
    printString(product->local);
    printf(".\n\n");
    printLine();
}

void printBasicProduct(Product *product) {
    char buffer[19 + 10 + MAX_NAME + 1];
    sprintf(buffer, "    %10d -> %s ", product->code, product->name);
    printAlignedLeft(buffer);
}

Product* scanProduct() {
    Product* product = (Product *)malloc(sizeof(Product));
    printf("\n\tNome: ");
    scanf("%[^\n]%*c", product->name);
    printf("\tCode: ");
    scanf("%d", &product->code);
    printf("\tNumber: ");
    scanf("%d", &product->number);
    printf("\tValue: ");
    scanf("%f%*c", &product->value);
    printf("\tLocal: ");
    scanf("%[^\n]%*c", product->local);
    printf("\n");
    return product;
}

void reset(char *str, int size) {
    int i;
    for(i = 0; i < size; i++)
        str[i] = '\0';
}
