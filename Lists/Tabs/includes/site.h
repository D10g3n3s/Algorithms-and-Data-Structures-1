#ifndef SITE_H
    #define SITE_H

    #include "bool.h"
    
    typedef struct _site SITE;

    SITE* createSite(char *title, char *site);
    char* siteGetTitle(SITE *site);
    char* siteGetLink(SITE *site);
    void printSite(SITE *site);
    bool deleteSite(SITE *site);

#endif