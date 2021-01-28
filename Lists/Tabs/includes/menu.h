#ifndef MENU_H
    #define MENU_H

    #include "list.h"

    enum {
        INSERT = 1,
        CHANGE,
        PRINT,
        EXIT
    };

    void menu(LIST *list);

#endif