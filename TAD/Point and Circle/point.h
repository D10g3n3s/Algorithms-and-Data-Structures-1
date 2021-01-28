#ifndef POINT_H
    #define PONTO_H
    #define TRUE 1
    #define FALSE 0
    #define boolean int

    typedef struct point_ POINT;

    POINT *create_point(float x, float y);
    void delete_point(POINT **point);
    boolean set_point(POINT *point, float new_x, float new_y);

    float get_x_point(POINT *point);
    float get_y_point(POINT *point);
    void print_point(POINT *point);

#endif