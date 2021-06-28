#ifndef ARG_LIST_H
#define ARG_LIST_H

#include "menu_defines.h"

int isEmptyArgList(ArgList head);

ArgList allocArgList();

ArgList addArgList(ArgList head, void *arg);

void freeArgList(ArgList head);

void printArgList(ArgList head);

#endif