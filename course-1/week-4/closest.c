#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
} point;

double min_distance(point x_sorted[], point y_sorted[], int pointsNumber, int lower, int upper);
double distance(point *a, point *b);
double min(int number, ...);
int x_sort(const void *a, const void *b);
int y_sort(const void *a, const void *b);

int main(void) {
    int pointsNumber;
    scanf("%d", &pointsNumber);

    point points[pointsNumber];
    for (int i = 0; i < pointsNumber; i++)
        scanf("%lf %lf", &points[i].x, &points[i].y);

    point *x_sorted = malloc(sizeof(point) * pointsNumber);
    point *y_sorted = malloc(sizeof(point) * pointsNumber);
    memcpy(x_sorted, points, sizeof(point) * pointsNumber);
    memcpy(y_sorted, points, sizeof(point) * pointsNumber);    
    qsort(x_sorted, pointsNumber, sizeof(point), x_sort);
    qsort(y_sorted, pointsNumber, sizeof(point), y_sort);
    

    printf("%lf\n", min_distance(x_sorted, y_sorted, pointsNumber, 0, pointsNumber));

    free(x_sorted);
    free(y_sorted);
}

double min_distance(point x_sorted[], point y_sorted[], int pointsNumber, int lower, int upper) {
    if (upper - lower == 2) return distance(&x_sorted[lower], &x_sorted[upper - 1]);
    if (upper - lower == 3) return min(3, distance(&x_sorted[lower], &x_sorted[lower + 1]), 
                                          distance(&x_sorted[lower + 1], &x_sorted[lower + 2]), 
                                          distance(&x_sorted[lower], &x_sorted[lower + 2]));
    
    int middle = lower + (upper - lower) / 2;
    double dl = min_distance(x_sorted, y_sorted, pointsNumber, lower, middle);
    double dr = min_distance(x_sorted, y_sorted, pointsNumber, middle, upper);
    double d = min(2, dl, dr);

    point *S = NULL;
    int S_length = 0;
    for (int i = 0; i < pointsNumber; i++) {
        if (y_sorted[i].x >= x_sorted[middle].x - d && y_sorted[i].x <= x_sorted[middle].x + d) {
            S = realloc(S, (++S_length) * sizeof(point));
            S[S_length - 1] = y_sorted[i];
        }
    }

    for (int i = 1; i < S_length; i++)
        for (int j = 1; j < 7; j++)
            d = min(2, d, distance(&S[i], &S[i + j]));

    free(S);
    
    return d;
}

double min(int number, ...) {
    va_list ptr;
    va_start(ptr, number);
    double min = va_arg(ptr, double);
    for (int i = 0; i < number - 1; i++) {
        double temp = va_arg(ptr, double);
        min = temp < min ? temp : min;
    }

    va_end(ptr);
    return min;
}

double distance(point *a, point *b) {
    double result = sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
    return result;
}

int x_sort(const void *a, const void *b) {
    return (((point *)a)->x - ((point *)b)->x);
}

int y_sort(const void *a, const void *b) {
    return (((point *)a)->y - ((point *)b)->y);
}