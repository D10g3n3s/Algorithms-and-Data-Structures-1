#include <stdio.h>
#include <stdlib.h>
#include "point.h"

//Creating the point struct
typedef struct point_{
    float x;
    float y;
} POINT;

//Function that creates a point by using x and y coordenates
POINT *create_point(float x, float y){
    POINT *point;
    
    point = (POINT *) malloc (sizeof(POINT));

    if (point != NULL){
        point->x = x;
        point->y = y;
    }

    return point;
}

//Function that deletes a point and deallocated the heap memory
void delete_point(POINT **point){
    if (*point != NULL){
        free(*point);
        *point = NULL;
    }
    else {
        printf("Error trying to delete your point!\n");
        exit(1);
    }
}

//Function that sets new coordenates for a point
boolean set_point(POINT *point, float new_x, float new_y){
    if (point != NULL){
        point->x = new_x;
        point->y = new_y;
        return TRUE;
    }
    
    return FALSE;
}

//Function that gets the x coordenate of a point
float get_x_point(POINT *point){
    if (point != NULL) return point->x;
    
    else {
        printf("You're trying to acess and NULL pointer\n");
        exit(1);
    }
}

//Function that gets the y coordanate of a point
float get_y_point(POINT *point){
    if (point != NULL) return point->y;

    else {
        printf("You're trying to acess and NULL pointer\n");
        exit(1);
    }
}

//Function that prints the coordinates of a point
void print_point(POINT *point){
    if (point != NULL){
        printf("Ponto, coord. x: %.1f\n", point->x);
        printf("Ponto, coord. y: %.1f\n", point->y);
    }
    else {
        printf("You're trying to print and NULL point!\n");
        exit(1);
    }
}