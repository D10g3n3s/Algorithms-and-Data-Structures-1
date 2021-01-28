#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "circle.h"

//Creating the circle struct
typedef struct circle_{
    POINT *center;
    int radius;
} CIRCLE;

//Funcion that creates a circle with a point and a radius
CIRCLE *create_circle(POINT *point, int radius){
    CIRCLE *circle;

    circle = (CIRCLE*) malloc (sizeof(CIRCLE));

    if (circle != NULL && point != NULL){
        circle->center = create_point(get_x_point(point), get_y_point(point));
        circle->radius = radius;
    }

    return circle;
}

//Function that sets new values for the circle center point
boolean set_circle_point(CIRCLE *circle, POINT *point){
    if (circle != NULL && circle->center != NULL && point != NULL){
        set_point(circle->center, get_x_point(point), get_y_point(point));
        return TRUE;
    }

    return FALSE;
}

//Function that sets new value for the circle radius
boolean set_circle_radius(CIRCLE *circle, int radius){
    if (circle != NULL){
        circle->radius = radius;
        return TRUE;
    }

    return FALSE;
}

//Funcion that gets the circle center point
POINT *get_circle_point(CIRCLE *circle){
    if (circle != NULL && circle->center != NULL) return circle->center;

    else {
        printf("Trying to acess and NULL pointer!\n");
        exit(1);
    }
}

//Function that gets the circle radius
int get_circle_radius (CIRCLE *circle){
    if (circle != NULL) return circle->radius;

    else {
        printf("Trying to acess and NULL pointer!\n");
        exit(1);
    }
}

//Fuctiont that deletes the circle and deallocates the heap memory
void delete_circle(CIRCLE **circle){
    if (*circle != NULL){
        free((*circle)->center);
        (*circle)->center = NULL;
        free(*circle);
        *circle = NULL;
    }

    else {
        printf("Trying to delete and NULL pointer!\n");
        exit(1);
    }
}

//Functoin that prints the circle center point and radius
void print_circle(CIRCLE *circle){
    if (circle != NULL){
        printf("Circulo, coord. x: %.1f\n", get_x_point(circle->center));
        printf("Circulo, coord. y: %.1f\n", get_y_point(circle->center));
        printf("Raio: %d\n", circle->radius);
    }
}