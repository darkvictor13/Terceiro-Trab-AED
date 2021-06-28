#include "arg_list.h"

int isEmptyArgList(ArgList head) {
    return head == NULL;
}

ArgList allocArgList() {
    return (ArgList)malloc(sizeof(Arg));
}

ArgList addArgList(ArgList head, void *arg) {
    if(isEmptyArgList(head->next)) {
        head->next = allocArgList();
        head->next->arg = arg;
    }else{
        addArgList(head->next, arg);
    }
    return head;
}

void freeArgList(ArgList head) {
    if(!isEmptyArgList(head->next))
        freeArgList(head->next);
    free(head);
}

void printArgList(ArgList head) {
    printf("->| ");
    if(!isEmptyArgList(head->next))
        printArgList(head->next);
}
