/**
 * @file search_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SEARCH_MENU_CONTROLLER_H
#define SEARCH_MENU_CONTROLLER_H

#include "../interfaces/input_file.h"
#include "../models/b_tree_prints.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

/**
 * @brief imprime o cabecalho do menu de busca
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuHeader();

/**
 * @brief imprime o rodape do menu de busca
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void searchMenuFooter();

/**
 * @brief cria o menu de busca e da inicio ao mesmo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int searchMenuController(ArgStack head);

/**
 * @brief entrada do menu principal para realizar a busca de um produto por codigo
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchProductByCode(ArgStack head);

/**
 * @brief entrada do menu principal para listar os produtos em ordem crescente
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionListProducts(ArgStack head);

/**
 * @brief entrada do menu principal para imprimir a arvore b por niveis
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintTree(ArgStack head);

/**
 * @brief entrada do menu principal para imprimir os dados contidos no arquivo que representa a arvore b
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintRegistryList(ArgStack head);

/**
 * @brief entrada do menu principal para imprimir os dados contidos no arquivo de dados
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintProductList(ArgStack head);

/**
 * @brief entrada do menu principal para imprimir a lista de espacos livres no arquivo que representa a arvore b
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeIndexSpaces(ArgStack head);

/**
 * @brief entrada do menu principal para imprimir a lista de espacos livres no arquivo de dados de produtos
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionPrintFreeDataSpaces(ArgStack head);

/**
 * @brief entrada do menu principal para retornar ao menu anterior
 * 
 * @param head lista de argumentos do menu
 * @return int sinaliza ao menu anterior se este deve permanecer ativo ou nao
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionSearchReturn(ArgStack head);

#endif
