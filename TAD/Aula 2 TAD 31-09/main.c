/*
 _____________________________________________________________
|     ___________________________________________________     |
|    |             Universidade de São Paulo             |    |
|    |                                                   |    |
|    | Instituto de Ciências Matemáticas e de Computação |    |
|    |                                                   |    |
|    |           Diógenes Silva Pedro BCC 020            |    |
|    |                                                   |    |
|    |                  nUSP: 11883476                   |    |
|    |                                                   |    |
|    |               diogenes.pedro@usp.br               |    |
|    |                                                   |    |
|    |            diogenes.pedro60@gmail.com             |    |
|    |                                                   |    |
|    |                                                   |    |
|    |                        TAD                        |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(){
    ITEM *item;

    item = create_item(15);
    print_item(item);

    int x = get_item_key(item);
    printf("Key getted: %d\n", x);

    set_item_key(item, 30);
    print_item(item);
    printf("Key getted: %d\n", x);

    delete_item(&item);

    return 0;
}