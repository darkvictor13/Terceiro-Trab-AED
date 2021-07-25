#include "../src/models/b_tree.h"

#define SIZE 1000

/**
 * @brief verifica se um valor se encontra num vetor
 * 
 * @param vector vetor de n elemntos
 * @param n numero de elementos do vetor
 * @param x numero a ser procurado no vetor
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool exist(int vector[], int n, int x) {
    for (int i = 0; i < n; i++)
        if(vector[i] == x)
            return TRUE;
    return FALSE;
}

/**
 * @brief teste da arvore b para insercao, busca e remocao
 * 
 * @param argc 
 * @param argv 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int main(int argc, char *argv[]) {
    char indexFilePath[] = "./index.bin";
    char dataFilePath[] = "./data.bin";
    BTree bTree = openBTreeFiles(indexFilePath, dataFilePath);
    Product *product = (Product*)malloc(sizeof(Product));
    strcpy(product->name, "ocupado");
    int numbers[SIZE];
    int inserted = 0;
    int finded = 0;
    int removed = 0;
    for(int i = 0; i < SIZE; i++) {
        while(exist(numbers, i, numbers[i] = rand() % (SIZE * 10)));
        //printf("  %d", numbers[i]);
    }
    printf("Total: %d\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        product->code = numbers[i];
        insertBTree(bTree, product);
        inserted++;
    }
    printf("Inserted: %d %s\n", inserted, (inserted == SIZE)? "[OK]" : "[ERROR]");
    int position;
    for(int i = 0; i < SIZE; i++) {
        if(searchBTreeByCode(bTree, numbers[i], &position))
            finded++;
    }
    printf("Finded: %d %s\n", finded, (finded == SIZE)? "[OK]" : "[ERROR]");
    for(int i = 0; i < SIZE; i++) {
        if(removeBTree(bTree, numbers[i]))
            removed++;
    }
    printf("Removed: %d %s\n", removed, (removed == SIZE)? "[OK]" : "[ERROR]");
    closeBTreeFiles(bTree);
    return 0;
}
