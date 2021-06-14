#include "menu/interfacemenu.h"
#include "menu/circularlist.h"

void headerPrincipal() {
    printLine();
    printAlignedCenter("Principal");
    printLine();
}

void footerPrincipal() {
    printLine();
    printAlignedRight("fim");
    printLine();
}

int teste(FILE *f) {
    printAlignedCenter("Fiz Nada");
    printWaitMenu();
    return 1;
}

int main () {
    Menu *m = createMenu();
    setHeader(m, headerPrincipal);
    setFooter(m, footerPrincipal);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    //controlMenu(m, NULL);
    List *l = NULL;
    l = insertAtEnd(l, 1);
    l = insertAtEnd(l, 2);
    l = insertAtEnd(l, 3);
    l = insertAtEnd(l, 4);
    l = insertAtEnd(l, 5);
    l = insertAtEnd(l, 6);
    printList(l->prev);
    free(l);
    return 0;
}
