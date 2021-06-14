#ifndef INTERFACE_MENU_H
#define INTERFACE_MENU_H

/**
 * @file interfacemenu.h
 * @author Victor Emanuel Almeida
 * @brief Arquivo responsável por definir todas as funções
 * que o usuário que utiliza o menu poderá chamar
 * @version 0.1
 * @date 14/06/2021
 */

#include "controllermenu.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Remove um dos itens do menu
 * 
 * @param queue ponteiro para uma estrutura que contém as informações de uma fila
 * @return int 
 * @pre Nenhuma
 * @post Retorna o valor do tamanho da fila reduzido
 */
int removeEntryQueue(EntryQueue *queue);

/**
 * @brief Insere um novo elemento na fila
 * 
 * @param queue ponteiro para uma estrutura que contém as 
 * informações de uma fila
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Nenhuma
 * @post Nenhuma
 */
void insertEntryQueue(EntryQueue *queue, char *message, CallbackFunct *funct);

/**
 * @brief Create a Menu object
 * 
 * @return Menu* 
 * @pre Nenhuma
 * @post Menu criado
 */
Menu *createMenu();

/**
 * @brief Adiciona mais uma opção ao menu passado por parâmetro
 * 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param message informação impressa no menu, resume o que a função faz
 * @param funct função a ser executada ao selecionar o item
 * @pre Menu carregado
 * @post Mais uma função ao menu
 */
void addEntryToMenu(Menu *menu, char *message, CallbackFunct *funct);

/**
 * @brief Conecta um menu a seu header
 * 
 * @param menu 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param header ponteiro para função de header
 * @pre Menu carregado
 * @post Menu possui um header
 */
void setHeader(Menu *menu, HeaderFunct header);

/**
 * @brief Conecta um menu a seu footer
 * 
 * @param menu 
 * @param menu ponteiro para uma estrutura que contém as 
 * informações de um menu
 * @param footer ponteiro para função de footer
 * @pre Menu carregado
 * @post Menu possui um footer
 */
void setFooter(Menu *menu, FooterFunct footer);

#endif //INTERFACE_MENU_H
