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
|    |                 Point and Circle                  |    |
|    |                                                   |    |
|    |___________________________________________________|    |
|_____________________________________________________________|
       |_______________________________________________|       
*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "circle.h"

int main(){
    float p_x, p_y, c_x, c_y;
    int radius;
    boolean inside_circle = FALSE;

    POINT *point;
    POINT *circle_point;
    CIRCLE *circle;
    
    scanf("%f %f %f %f %d", &p_x, &p_y, &c_x, &c_y, &radius);

    point = create_point(p_x, p_y);
    print_point(point);

    circle_point = create_point(c_x, c_y);
    circle = create_circle(circle_point, radius);
    
    inside_circle = inside_outside(point, circle); 

    if(inside_circle) 
        printf("O ponto x = %.0f, y = %.0f é interior ao círculo\n", get_x_point(point), get_y_point(point));
    else 
        printf("O ponto x = %.0f, y = %.0f é exterior ao círculo\n", get_x_point(point), get_y_point(point));

    delete_point(&circle_point);
    delete_point(&point);
    delete_circle(&circle);

    return 0;
}