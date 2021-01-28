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
    float x, y;
    int radius;

    POINT *point;
    CIRCLE *circle;
    
    scanf("%f %f %d", &x, &y, &radius);

    point = create_point(x, y);
    print_point(point);

    circle = create_circle(point, radius);
    print_circle(circle);

    delete_point(&point);
    delete_circle(&circle);

    return 0;
}