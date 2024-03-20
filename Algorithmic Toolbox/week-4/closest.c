#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    double x;
    double y;
} point;

// void stress_test(void);
double naive_distance(int pointsNumber, point points[]);
double min_distance(point x_sorted[], point y_sorted[], int pointsNumber, int lower, int upper);
double distance(point *a, point *b);
double min(int number, ...);
int x_sort(const void *a, const void *b);
int y_sort(const void *a, const void *b);

int main(void) {
    // srand(time(NULL));
    // stress_test();

    int pointsNumber;
    scanf("%d", &pointsNumber);

    point *points = malloc(sizeof(point) * pointsNumber);
    for (int i = 0; i < pointsNumber; i++)
        scanf("%lf %lf", &points[i].x, &points[i].y);

    point *y_sorted = malloc(sizeof(point) * pointsNumber);
    memcpy(y_sorted, points, sizeof(point) * pointsNumber);    
    qsort(points, pointsNumber, sizeof(point), x_sort);
    qsort(y_sorted, pointsNumber, sizeof(point), y_sort);
    
    // printf("Naive algorithm: %.17f\n", naive_distance(pointsNumber, points));
    printf("%.5f\n", min_distance(points, y_sorted, pointsNumber, 0, pointsNumber));

    free(points);
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
        if (y_sorted[i].x >= (x_sorted[middle].x - d) && y_sorted[i].x <= (x_sorted[middle].x + d)) {
            S = realloc(S, (++S_length) * sizeof(point));
            S[S_length - 1] = y_sorted[i];
        }
    }

    for (int i = 0; i < S_length; i++)
        for (int j = 0; j < 7; j++)
            if (i < S_length && i + j < S_length && i != i + j)
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
    // printf("d (%f %f) (%f %f) = %f\n", a->x, a->y, b->x, b->y, result);
    return result;
}

int x_sort(const void *a, const void *b) {
    return (((point *)a)->x > ((point *)b)->x) ? 1 : (((point *)a)->x < ((point *)b)->x) ? -1 : 0;
}

int y_sort(const void *a, const void *b) {
    return (((point *)a)->y > ((point *)b)->y) ? 1 : (((point *)a)->y < ((point *)b)->y) ? -1 : 0;
}

// double naive_distance(int pointsNumber, point points[]) {
//     double min = distance(&points[0], &points[1]);
//     for (int i = 0; i < pointsNumber; i++) {
//         for (int j = 0; j < pointsNumber; j++) {
//             if (i != j && distance(&points[i], &points[j]) < min) {
//                 min = distance(&points[i], &points[j]);
//             }
//         }
//     }

//     return min;
// }

// void stress_test(void) {
//     int pointsNumber = (rand() % (10 - 2 + 1)) + 2;
//     point points[pointsNumber];
//     for (int i = 0; i < pointsNumber; i++) {
//         do {
//             points[i].x = (rand() % (10000 + 10000 + 1)) - 10000;
//             points[i].y = (rand() % (10000 + 10000 + 1)) - 10000;
//         } while (points[i].x == points[i].y);
//     }

//     point *x_sorted = malloc(sizeof(point) * pointsNumber);
//     point *y_sorted = malloc(sizeof(point) * pointsNumber);
//     memcpy(x_sorted, points, sizeof(point) * pointsNumber);
//     memcpy(y_sorted, points, sizeof(point) * pointsNumber);    
//     qsort(x_sorted, pointsNumber, sizeof(point), x_sort);
//     qsort(y_sorted, pointsNumber, sizeof(point), y_sort);

//     for (int i = 0; i < pointsNumber; i++)
//         printf("%f %f\n", points[i].x, points[i].y);

//     printf("Naive algorithm: %.17f\n", naive_distance(pointsNumber, points));
//     printf("%.17f\n", min_distance(x_sorted, y_sorted, pointsNumber, 0, pointsNumber));

//     free(x_sorted);
//     free(y_sorted);
// }