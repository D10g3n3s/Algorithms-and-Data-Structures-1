#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "circle.h"

//Creating the circle struct
typedef struct circle_{
    POINT *center;
    int radius;
} CIRCLE;

//Funcion that creates a circle with a point and a radius
CIRCLE *create_circle(POINT *point, float radius){
    CIRCLE *circle;

    circle = (CIRCLE*) malloc (sizeof(CIRCLE));

    if (circle != NULL && point != NULL){
        circle->center = create_point(get_x_point(point), get_y_point(point));
        circle->radius = (int) radius;
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

//Fuction that deletes the circle and deallocates the heap memory
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

/*
Function that calculates if a point is inside a circle, I'm using the calculation inside the circle
because a circle should know if a point is or isn't inside itself 
*/
boolean inside_outside(POINT *point, CIRCLE *circle){
    if (circle != NULL && point != NULL){
        int d = sqrt(pow(get_x_point(circle->center) - get_x_point(point), 2) + 
                        pow(get_y_point(circle->center) - get_y_point(point) , 2));
        
        if (d <= circle->radius) return TRUE; //Point inside the circle
        
    }
    return FALSE; //Point outside the circle
}