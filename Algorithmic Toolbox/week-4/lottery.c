#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} segment;

int compare_segments(const void *a, const void *b);
int count_segments(segment segments[], int segmentsNumber, int point, int lower, int upper);
int check_segment(segment segments[], int numberOfSegment, int direction, int point, int segmentsNumber);

int main() {
    int segmentsNumber, pointsNumber;
    scanf("%d %d", &segmentsNumber, &pointsNumber);

    segment segments[segmentsNumber];
    for (int i = 0; i < segmentsNumber; i++)
        scanf("%d %d", &segments[i].start, &segments[i].end);
    
    int points[pointsNumber];
    for (int i = 0; i < pointsNumber; i++)
        scanf("%d", &points[i]);

    qsort(segments, segmentsNumber, sizeof(segment), compare_segments);

    for (int i = 0; i < pointsNumber; i++)
        printf("%d ", count_segments(segments, segmentsNumber, points[i], 0, segmentsNumber));
    printf("\n");
}

int compare_segments(const void *a, const void *b) {
    if (((segment *)a)->start == ((segment *)b)->start)
        return ((segment *)a)->end - ((segment *)b)->end;
    return ((segment *)a)->start - ((segment *)b)->start;
}

int count_segments(segment segments[], int segmentsNumber, int point, int lower, int upper) {
    if (upper <= lower) return 0;

    int counter = 0;
    int middle = lower + (upper - lower) / 2;
    if (segments[middle].start <= point && segments[middle].end >= point)
        counter += 1 + check_segment(segments, middle - 1, -1, point, segmentsNumber) + check_segment(segments, middle + 1, 1, point, segmentsNumber);
    else if (segments[middle].start > point)
        counter += count_segments(segments, segmentsNumber, point, lower, middle);
    else
        counter += count_segments(segments, segmentsNumber, point, middle + 1, upper);

    return counter;
}

int check_segment(segment segments[], int numberOfSegment, int direction, int point, int segmentsNumber) {
    if (numberOfSegment < 0 || numberOfSegment >= segmentsNumber) return 0;

    int count = 0;

    if ((segments[numberOfSegment].start <= point && segments[numberOfSegment].end >= point) || (segments[numberOfSegment].start == segments[numberOfSegment].end)) {
        if ((segments[numberOfSegment].start <= point && segments[numberOfSegment].end >= point)) count++;
        switch (direction) {
            case -1:
                count += check_segment(segments, numberOfSegment - 1, -1, point, segmentsNumber);
                break;
            case 1:
                count += check_segment(segments, numberOfSegment + 1, 1, point, segmentsNumber);
                break;            
        }
    }

    return count;
}