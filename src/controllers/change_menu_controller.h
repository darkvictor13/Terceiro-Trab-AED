/**
 * @file change_menu_controller.h
 * @author Marco-Guerra
 * @brief 
 * @version 0.1
 * @date 19/07/2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CHANGE_MENU_CONTROLLER_H
#define CHANGE_MENU_CONTROLLER_H

#include "confirm_menu_controller.h"
#include "../interfaces/input_file.h"
#include "../menu/controller_menu.h"
#include "../menu/print_menu.h"
#include "../menu/arg_list.h"

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuHeader();

/**
 * @brief 
 * 
 * @pre Nenhuma
 * @post Nenhuma
 */
void changeMenuFooter();

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int changeMenuController(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeNumber(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeValue(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeLocal(ArgStack head);

/**
 * @brief 
 * 
 * @param head 
 * @return int 
 * @pre Nenhuma
 * @post Nenhuma
 */
int actionChangeReturn(ArgStack head);

#endif
