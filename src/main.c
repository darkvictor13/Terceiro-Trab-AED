#include "menu/interfacemenu.h"

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
    m->footer = footerPrincipal;
    m->header = headerPrincipal;
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    controlMenu(m, NULL);
    return 0;
}
