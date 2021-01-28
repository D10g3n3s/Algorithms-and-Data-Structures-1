#ifndef LIST_H
    #define LIST_H

    #include "site.h"

    typedef struct _list LIST;

    LIST* createList();
    int listLength(LIST *list);
    bool listEmpty(LIST *list);
    bool insertList(LIST *list, SITE *site);
    SITE* searchList(LIST *list, char *title);
    void printList(LIST *list);
    bool deleteList(LIST *list);
    bool swapSite(LIST *list, char *title, int newPos);

#endif