/**
 * @file tree.c
 * @author Victor Emanuel Almeida (victoralmeida2001@hotmail.com)
 * @brief Arquivo responsável por implementar a arvore no arquivo
 * @version 0.1
 * @date 31/05/2021
 */

#include "tree.h"


/**
 * @brief Escreve o um campo do nó da arvore no arquivo
 * 
 * @param value 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void writeNodeField(int value, int nodeData, int position, FILE *dataFile) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fwrite(&value, sizeof(int), 1, dataFile);
}

/**
 * @brief Lê o um campo do nó da arvore no arquivo
 * 
 * @param nodeData 
 * @param position 
 * @param dataFile 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int readNodeField(int nodeData, int position, FILE *dataFile) {
    int value;
    fseek(dataFile, sizeof(Head) + position * sizeof(Node) + nodeData, SEEK_SET);
    fread(&value, sizeof(int), 1, dataFile);
    return value;
}

/**
 * @brief 
 * @brief Lê o produto de um nó da arvore no arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return Product* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Product* readNodeProduct(FILE *dataFile, int position) {
    Product *product = (Product *)malloc(sizeof(Product));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(product, sizeof(Product), 1, dataFile);
    return product;
}

/**
 * @brief Cria o Arquivo binário se ele não existe
 * 
 * @param filePath 
 * @return FILE* 
 * @pre Nenhuma
 * @post Nenhuma
 */
FILE *makeDataFile(char *filePath) {
    FILE *dataFile = fopen(filePath, "w+b");
    setbuf(dataFile, NULL);
    Head head;
    head.regRoot = head.regFree = -1;
    head.regLast = 0;
    writeHead(&head, dataFile);
    return dataFile;
}

/**
 * @brief Escreve um nó
 * 
 * @param dataFile 
 * @param node 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int writeNode(FILE *dataFile, Node *node, int position) {
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fwrite(node, sizeof(Node), 1, dataFile);
    return position;
}

/**
 * @brief Cria um nó da arvore a partir de um produto
 * 
 * @param product 
 * @param rChild 
 * @param lChild 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *makeNode(Product *product, int rChild, int lChild) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->product = (*product);
    node->rChild = rChild;
    node->lChild = lChild;
    return node;
}

/**
 * @brief Lê um nó do arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return Node* 
 * @pre Nenhuma
 * @post Nenhuma
 */
Node *readNode(FILE *dataFile, int position) {
    Node *node = (Node*)malloc(sizeof(Node));
    fseek(dataFile, sizeof(Head) + position * sizeof(Node), SEEK_SET);
    fread(node, sizeof(Node), 1, dataFile);
    return node;
}

/**
 * @brief Insere um nó do arquivo
 * 
 * @param dataFile 
 * @param node 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int insertNode(FILE *dataFile, Node *node) {
    int position = readHeadField(OFFSET_REG_FREE, dataFile);
    if(position == -1) {
        writeHeadField(
            (position = readHeadField(OFFSET_REG_LAST, dataFile)) + 1, 
            OFFSET_REG_LAST, 
            dataFile
        );
    }else{
        writeHeadField(
            readNodeField(OFFSET_NODE_RIGHT, position, dataFile), 
            OFFSET_REG_FREE, 
            dataFile
        );
    }
    return writeNode(dataFile, node, position);
}

/**
 * @brief Remove um nó do arquivo
 * 
 * @param dataFile 
 * @param position 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int removeNode(FILE *dataFile, int position) {
    Node *node = allocNode();
    node->rChild = readHeadField(OFFSET_REG_FREE, dataFile);
    writeHeadField(position, OFFSET_REG_FREE, dataFile);
    writeNode(dataFile, node, position);
    free(node);
    return 0;
}

/**
 * @brief Chama a função que imprime a arvore caso ela não seja vazia
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrder(FILE *dataFile) {
    if (isEmpty(dataFile))
        printAlignedCenter("Arvore vazia.");
    else
        printInOrderRec(dataFile, readHeadField(OFFSET_REG_ROOT, dataFile));
}

/**
 * @brief Imprime em ordem crescende de código a arvore
 * 
 * @param dataFile 
 * @param this 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printInOrderRec(FILE *dataFile, int this) {
    if (this == -1)
        return;
    printInOrderRec(
        dataFile,
        readNodeField(OFFSET_NODE_LEFT, this, dataFile)
    );
    Product *product;
    printBasicProduct(product = readNodeProduct(dataFile, this));
    free(product);
    printInOrderRec(
        dataFile,
        readNodeField(OFFSET_NODE_RIGHT, this, dataFile)
    );
}

/**
 * @brief Imprime a arvore em níveis
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printByLevel(FILE *dataFile) {
    if(isEmpty(dataFile)) {
        printAlignedCenter("Arvore vazia.");
        return;
    }
    int next = readHeadField(OFFSET_REG_ROOT, dataFile);
    Queue *queue = createQueue();
    insertQueue(queue, next, 1);
    int previous_height = 0;
    int current_height;
    int read;
    while(!emptyQueue(queue)) {
        current_height = queue->head->tabs;
        next = removeQueue(queue);
        if(previous_height < current_height) {
            previous_height = current_height;
            printf("\n\tNivel %d: ", current_height);
        }
        printf("/t%d", readNodeField(OFFSET_NODE_CODE, next, dataFile));
        if((read = readNodeField(OFFSET_NODE_LEFT, next, dataFile)) != -1)
            insertQueue(queue, read, current_height + 1);
        if((read = readNodeField(OFFSET_NODE_RIGHT, next, dataFile)) != -1)
            insertQueue(queue, read, current_height + 1);
    }
    printf("\n\n");
}

/**
 * @brief Tenta imprimir no menu todas as posições livres
 * 
 * @param dataFile 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFree(FILE *dataFile) {
    printFreeRec(
        dataFile,
        readHeadField(OFFSET_REG_FREE, dataFile)
    );
}

/**
 * @brief Imprime no menu todas as posições livres
 * 
 * @param dataFile 
 * @param this 
 * @pre Nenhuma
 * @post Nenhuma
 */
void printFreeRec(FILE *dataFile, int this) {
    if (this == -1)
        return ;
    char *buffer = malloc(sizeof(char) * 21); // maior inteiro de 8 bytes
    sprintf(buffer, "%d", this);
    printAlignedLeft(buffer);
    free(buffer);
    printFreeRec(
        dataFile,
        readNodeField(OFFSET_NODE_RIGHT, this, dataFile)
    );
}