#ifndef CIRCLE_H
    #define CIRCLE_H
    #define TRUE 1
    #define FALSE 0
    #define boolean int

    #include "point.h"

    typedef struct circle_ CIRCLE;

    CIRCLE *create_circle(POINT *point, int radius);
    boolean set_circle_point(CIRCLE *circle, POINT *point);
    boolean set_circle_radius(CIRCLE *circle, int radius);
    POINT *get_circle_point(CIRCLE *circle);
    int get_circle_radius (CIRCLE *circle);
    void delete_circle(CIRCLE **circle);
    void print_circle(CIRCLE *circle);

#endif