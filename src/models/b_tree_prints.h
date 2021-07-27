/**
 * @file b_tree_prints.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef B_TREE_PRINTS_H
#define B_TREE_PRINTS_H

#include "b_tree.h"

/**
 * @brief imprime os elementos de uma arbore b em ordem
 * 
 * @param bTree arvore b a ser imprimessa
 * @param position posicao atual do percorrimento da arvore
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeInOrderRec(BTree bTree, int position);

/**
 * @brief imprime o s elementos de uma arvore b em ordem
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeInOrder(BTree bTree);

/**
 * @brief immprime os codigos de uma arvore b por niveis
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeByLevel(BTree bTree);

/**
 * @brief imprime um registro em um canvas
 * 
 * @param registry registro a ser impresso
 * @param position posicao na lista de registros do arquivo
 * @param canvas canvas on de sera impresso o registro
 * @param x posicao do registro no eixo x dentro do canvas
 * @param y posicao do registro no eixo y dentro do canvas
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeRegistry(Registry *registry, int position, Canvas canvas, int x, int y);

/**
 * @brief imprime uma lista de registros na saida estandar
 * 
 * @param bTree arvore b a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeRegistryList(BTree bTree);

/**
 * @brief imprime os registros dentro do arquivo de dados
 * 
 * @param bTree arvore b a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeProductList(BTree bTree);

/**
 * @brief imprime a lista de regsitros libres no arquivo que representa a arvore
 * 
 * @param bTree arvore a ser impressa
 * @param position posicao atual na lista de registros
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeIndexRec(BTree bTree, int position);

/**
 * @brief imprime a lista de regsitros libres no arquivo que representa a arvore
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeIndex(BTree bTree);

/**
 * @brief imprime a lista de registros libres no arquivo que contem os dados dos produtos
 * 
 * @param bTree arvore a ser impressa
 * @param position posicao atual na lista de dados
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeDataRec(BTree bTree, int position);

/**
 * @brief imprime a lista de registros libres no arquivo que contem os dados dos produtos
 * 
 * @param bTree arvore a ser impressa
 * @pre Nenhuma
 * @post Nenhuma
 */
void printBTreeFreeData(BTree bTree);

#endif