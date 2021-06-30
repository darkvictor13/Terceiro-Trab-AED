#include "confirm_menu_controller.h"

void confirmMenuHeader() {
    printLine();
    printAlignedCenter("Desea realmente realizar esa acao?");
    printLine();
}

void confirmMenuFooter() {
    printLine();
    printAlignedRight("");
    printLine();
}

int confirmMenuController(ArgStack head) {
    Menu *confirmMenu = createMenu();
    setHeader(confirmMenu, confirmMenuHeader);
    setFooter(confirmMenu, confirmMenuFooter);
    addEntryToMenu(confirmMenu, "Sim.", actionConfirmYes);
    addEntryToMenu(confirmMenu, "No.", actionConfirmNo);
    controlMenu(confirmMenu, head);
    return 0;
}

int actionConfirmYes(ArgStack head) {
    pushArgStack(head, (void*)1);
    return 0;
}

int actionConfirmNo(ArgStack head) {
    pushArgStack(head, (void*)0);
    return 0;
}
