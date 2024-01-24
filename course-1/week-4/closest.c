#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int main(void) {
    int pointsNumber;
    scanf("%d", &pointsNumber);

    point points[pointsNumber];
    for (int i = 0; i < pointsNumber; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
}