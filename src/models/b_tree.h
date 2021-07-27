/**
 * @file b_tree.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef B_TREE_H
#define B_TREE_H

#include "../menu/canvas.h"
#include "index_file.h"
#include "data_file.h"
#include "product.h"
#include "queue.h"

/**
 * @brief modo de abertura dos arquivos
 */
#define OPEN_MODE "r+b"

/**
 * @brief Modos de shift
 */
enum {
    LEND_TO_LEFT,
    LEND_TO_RIGHT
};

/**
 * @brief Definindo um tipo booleano
 * 
 * facilitando e restringindo o retorno
 * de funções booleanas
 */
typedef enum {
    FALSE,
    TRUE
}Bool;

/**
 * @brief Ponteiros para os arquivos que
 * representam a árvore B e seus dados
 */
typedef struct {
    FILE *indexFile;
    FILE *dataFile;
}NodeBTree;

typedef NodeBTree* BTree;

/**
 * @brief abre os arquivos que contem os dados da arvore
 * 
 * @param indexFilePath lista de carateres contendo o nome e localizacao do arquivo a ser utilizado para guardar a representacao da arvore
 * @param dataFilePath lista de carateres contendo o nome e localizacao do arquivo a ser utilizado para armazenar os dados dos produtos
 * @return BTree arvore recem aberta ou criada
 * @pre Nenhuma
 * @post Nenhuma
 */
BTree openBTreeFiles(char *indexFilePath, char *dataFilePath);

/**
 * @brief fecha os arquivos contendo a arvore b e seus dados
 * 
 * @param bTree arvore b a ser fechada
 * @pre Nenhuma
 * @post Nenhuma
 */
void closeBTreeFiles(BTree bTree);

/**
 * @brief realiza a troca de dois inteiros
 * 
 * @param valueA endereco do inteiro A
 * @param valueB endereco do inteiro B
 * @pre Nenhuma
 * @post Nenhuma
 */
void swapIntegers(int *valueA, int *valueB);

/**
 * @brief indica se uma arvore b se encontra vazia ou nao
 * 
 * @param bTree arvore b que se deseja saber se contem elementos 
 * @return Bool valor indicando se a arvore b contem ou nao elementos
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isEmptyBTree(BTree bTree);

/**
 * @brief indica se um dado registro dentro de uma arvore b e folha ou nao
 * 
 * @param registry registro que se deseja saber se e folha ou nao
 * @return Bool valor indicando se o registro pasado e folha ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isLeafBTree(Registry *registry);

/**
 * @brief indica se um registro se encontra cheio ou nao
 * 
 * @param registry registro do qual se deseja saber seu estado
 * @return Bool valor indicando o estado do registro
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isRegistryFull(Registry *registry);

/**
 * @brief indica se um registro se encontra com menos elementos do necessario
 * 
 * @param registry registro do qual se deseja saber sua condicao
 * @return Bool valor indicando o estado de um registro
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool isRegistryUnderFlow(Registry *registry);

/**
 * @brief indica se um registro pode ou nao perder um valor sem perder a sua condicao
 * 
 * @param bTree arvore b onde se encontra o registro a ser revisado
 * @param position posicao do registro a ser revisado
 * @return Bool 
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool canRegistryBorrow(BTree bTree, int position);

/**
 * @brief busca um elemento dentro de uma arvore b
 * 
 * @param bTree arvore b onde sera feita a busca
 * @param registryPosition posicao onde se devera buscar o registro atual no arquivo
 * @param key chave que identifica qualk registro esta sendo buscado
 * @param position posicao onde sera colocado o endereco do registro quandop achado
 * @return Bool valor indicado se o registro foi acho de fato
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchBTreeByCodeRec(BTree bTree, int registryPosition, int key, int *position);

/**
 * @brief busca um elemento dentro de uma arvore b
 * 
 * @param bTree arvore b onde sera feita a busca
 * @param key chave que identifica qualk registro esta sendo buscado
 * @param position posicao onde sera colocado o endereco do registro quandop achado
 * @return Bool valor indicado se o registro foi acho de fato
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchBTreeByCode(BTree bTree, int key, int *position);

/**
 * @brief busca em que posicao deveria estar um valor dentro de um registro
 * 
 * @param registry registro onde sera buscada a posicao
 * @param key chave que identifica a posicao a ser buscada
 * @param position posicao onde sera colocado o endereco do registro quandop achado
 * @return Bool valor indicado se o registro foi acho de fato
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool searchPositionBTRee(Registry *registry, int key, int *position);

/**
 * @brief adiciona um elemento a uma lista de registros
 * 
 * @param registry registro onde sera adicionado o elemento
 * @param registryField elemento a ser adicionado ao registro
 * @pre Nenhuma
 * @post Nenhuma
 */
void simpleAddBTree(Registry *registry, RegistryField *registryField);

/**
 * @brief separa um registro em dois e adiciona um elemento a um deles
 * 
 * @param bTree arvore b onde serao armazenados os registros
 * @param registry registro a ser dividido
 * @param position posisao no arquivo do registro que sera dividido
 * @param registryField elemento a ser incorporado no registro
 * @return RegistryField* registro promovido
 * @pre Nenhuma
 * @post Nenhuma
 */
RegistryField *splitAddBTree(BTree bTree, Registry *registry, int position, RegistryField *registryField);

/**
 * @brief isere um novo elemento na arvore b
 * 
 * @param bTree arvore b onde sera inserido o elemento
 * @param position posicao atual da busca pelo lugar onde sera inserido o elemento
 * @param product produto a ser inserido
 * @return RegistryField* registro promovido durante a insercao
 * @pre Nenhuma
 * @post Nenhuma
 */
RegistryField *insertBTreeRec(BTree bTree, int position, Product *product);

/**
 * @brief isere um novo elemento na arvore b
 * 
 * @param bTree arvore b onde sera inserido o elemento
 * @param product  produto a ser inserido
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertBTree(BTree bTree, Product *product);

/**
 * @brief le um produto do arquivo de produtos
 * 
 * @param bTree arvore de onde sera lido o produto
 * @param position posicao onde se encontra o produto a ser lido
 * @return Product* ponteiro para o produto lido
 * @pre Nenhuma
 * @post Nenhuma
 */
Product *getBTreeProduct(BTree bTree, int position);

/**
 * @brief atualiza um produto dentro do arquivo de dafos da arvore b
 * 
 * @param bTree arvore b onde sera atualizado o produto
 * @param position posicao onde sera escrito o produto
 * @param product produto a ser escrito
 * @pre Nenhuma
 * @post Nenhuma
 */
void updateBTreeProduct(BTree bTree, int position, Product *product);

/**
 * @brief realiza a remocao de um elemento dentro de um registrp
 * 
 * @param registry registro de onde sera eliminado um elemento
 * @param position posicao em que se encontra o produto a eliminar
 * @pre Nenhuma
 * @post Nenhuma
 */
void simpleRemoveBTree(Registry *registry, int position);

/**
 * @brief sobreescreve um elemento do registro com o elemento dentro do filho que le segue
 * 
 * @param bTree arvore b onde se encontra o elemento filho
 * @param registry registro pai que tera um elemento sobreecrito
 * @param position posicao do elemento que sera sobreescrito
 * @pre o elemento sobreescrito devera ter seu registro de produto previamente liverado
 * @post Nenhuma
 */
void overwriteBTree(BTree bTree, Registry *registry, int position);

/**
 * @brief realiza o emprestimo entre os filhos de um elemento
 * 
 * @param bTree arvore b contendo os registros entre os quais ira acontecer o emprestimo
 * @param lendTo indica se o emprestimo ira acontecer da esquerda para a direita ou da direita para a esquerda
 * @param father registro que contem os registros entre os quais acontecera o emprestimo
 * @param position elemento pai dos filhos entre os quais acontecera um emprestimo
 * @pre Nenhuma
 * @post Nenhuma
 */
void lendBTreeChildren(BTree bTree, int lendTo, Registry *father, int position);

/**
 * @brief concatena dois registro
 * 
 * @param bTree arvore onde se encontram os registros a serem concatenados
 * @param father registro que contem os elementos a seremn concatenados
 * @param position posicao do elemento que tera seus filhos concatenados
 * @pre Nenhuma
 * @post Nenhuma
 */
void concatenateBTreeChildren(BTree bTree, Registry *father, int position);

/**
 * @brief remove um elemento dentro de uma arvore b
 * 
 * @param bTree arvore b contendo da qual se deseja remover um elemento
 * @param position posicao dentro do arquivo do registro atual em que sera buscado o elemento a remover
 * @param code codigo do elemento a remover
 * @return Bool valor indicando se o elemento a ser rfemoviddo foi encontrado na arvore
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool removeBTreeRec(BTree bTree, int *position, int code);

/**
 * @brief remove um elemento dentro de uma arvore b
 * 
 * @param bTree arvore b da qual se deseja remover um elemento
 * @param code codigo do elemento a remover
 * @return Bool valor indicando se o elemento a ser rfemoviddo foi encontrado na arvore
 * @pre Nenhuma
 * @post Nenhuma
 */
Bool removeBTree(BTree bTree, int code);

#endif
