#include "arg_list.h"

int isEmptyArgList(ArgList head) {
    return head == NULL;
}

ArgList allocArgList() {
    return (ArgList)malloc(sizeof(Arg));
}

ArgList addArgList(ArgList head, void *arg) {
    ArgList newHead = allocArgList();
    newHead->next = head;
    newHead->arg = arg;
    return newHead;
}

void freeArgList(ArgList head) {
    if(!isEmptyArgList(head)) {
        freeArgList(head->next);
        free(head);
    }
}

void printArgList(ArgList head) {
    if(!isEmptyArgList(head)) {
        printArgList(head->next);
        printf("->| ");
    }
}
