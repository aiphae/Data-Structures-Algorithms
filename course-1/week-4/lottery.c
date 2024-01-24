#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} segment;

void sort_segments(segment segments[], int segmentsNumber);
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

    sort_segments(segments, segmentsNumber);

    for (int i = 0; i < pointsNumber; i++)
        printf("%d ", count_segments(segments, segmentsNumber, points[i], 0, segmentsNumber));
    printf("\n");
}

void sort_segments(segment segments[], int segmentsNumber) {
    segment temp;
    int index;
    for (int i = 0; i < segmentsNumber; i++) {
        index = i;
        for (int j = i + 1; j < segmentsNumber; j++) {
            if (segments[j].start < segments[index].start)
                index = i;
            else if (segments[j].start == segments[index].start) {
                if (segments[j].end < segments[index].end)
                    index = j;
            }
        }
        temp = segments[i];
        segments[i] = segments[index];
        segments[index] = temp;
    }
}

int count_segments(segment segments[], int segmentsNumber, int point, int lower, int upper) {
    if (upper < lower) return 0;

    int counter = 0;
    int middle = lower + (upper - lower) / 2;
    if (segments[middle].start <= point && segments[middle].end >= point)
        counter += 1 + check_segment(segments, middle - 1, -1, point, segmentsNumber) + check_segment(segments, middle + 1, 1, point, segmentsNumber);
    else if (segments[middle].start > point)
        counter += count_segments(segments, segmentsNumber, point, lower, middle - 1);
    else
        counter += count_segments(segments, segmentsNumber, point, middle + 1, upper);

    return counter;
}

int check_segment(segment segments[], int numberOfSegment, int direction, int point, int segmentsNumber) {
    if (numberOfSegment < 0 || numberOfSegment >= segmentsNumber) return 0;

    if (segments[numberOfSegment].start <= point && segments[numberOfSegment].end >= point)
        switch (direction) {
            case -1:
                return 1 + check_segment(segments, numberOfSegment - 1, -1, point, segmentsNumber);
                break;
            case 1:
                return 1 + check_segment(segments, numberOfSegment - 1, 1, point, segmentsNumber);
                break;
        }
    
    return 0;
}