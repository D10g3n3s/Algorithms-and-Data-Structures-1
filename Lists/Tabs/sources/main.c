#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int main(){
    LIST *list = createList();

    menu(list);

    deleteList(list);

    return 0;
}