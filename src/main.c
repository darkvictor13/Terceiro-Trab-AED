#include "menu/interfacemenu.h"
#include "menu/circularlist.h"
#include "menu/printmenu.h"

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
    printAlignedCenter("Ola");
    printAlignedCenter("Oi");
    setHeader(m, headerPrincipal);
    setFooter(m, footerPrincipal);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    addEntryToMenu(m, "Alguma coisa", teste);
    controlMenu(m, NULL);
    free(m);
    return 0;
}
