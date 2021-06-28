#ifndef MENU_DEFINES_H
#define MENU_DEFINES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "utilities.h"

#ifdef __gnu_linux__

#define ENTER 10
#define CLEAR "clear"

#else

#define ENTER 13
#define CLEAR "cls"

#endif //__gnu_linux__

#define MESSAGE_SIZE 101
#define SELECT_SIZE 10
#define SIZE_LINE MESSAGE_SIZE + SELECT_SIZE

#define UP 'w'
#define DOWN 's'

enum {
    MOVE_BACKWARD,
    MOVE_FOWARD
};

typedef struct argNode {
    void *arg;
    struct argNode *next;
}Arg;

typedef Arg* ArgList;

typedef int CallbackFunct(ArgList head);
typedef void HeaderFunct();
typedef void FooterFunct();

typedef struct entryNode {
    int number;
	char entryMessage[MESSAGE_SIZE];
    CallbackFunct *funct;
    struct entryNode *next;
    struct entryNode *prev;
}Entry;

typedef Entry* EntryList;

typedef struct {
    FooterFunct *footer;
    HeaderFunct *header;
    EntryList first;
    EntryList selected;
}Menu;

#endif