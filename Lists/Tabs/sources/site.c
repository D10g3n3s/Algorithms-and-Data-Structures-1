#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "site.h"

struct _site{
    char *title;
    char *link;
};

//Function that creates a site
SITE* createSite(char *title, char *link){
    SITE *site = malloc(sizeof(SITE));

    if (site != NULL){
        site->title = title;
        site->link = link;
    }

    return site;
}

//Function that gets a title given a site
char* siteGetTitle(SITE *site){
    if (site != NULL)
        return site->title;
    else
        return NULL;
}

//Function that gets a link given a site
char* siteGetLink(SITE *site){
    if (site != NULL)
        return site->link;
    else
        return NULL;
}

//Function that prints a site
void printSite(SITE *site){
    if (site != NULL)
        printf("%s %s\n", site->title, site->link);
}

//Functiont that deallocates a site memory and deletes it
bool deleteSite(SITE *site){
    if (site != NULL){
        free(site->title);
        free(site->link);
        free(site);
        return TRUE;
    }
    else
        return FALSE;
}