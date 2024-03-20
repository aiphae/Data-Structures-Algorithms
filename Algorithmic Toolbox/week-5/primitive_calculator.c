#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void primitive_calculator(int number);
int min(int a, int b, int c);

int main(void) {
    int number;
    scanf("%d", &number);

    primitive_calculator(number);
}

void primitive_calculator(int number) {
    int *minSteps = malloc(sizeof(int) * (number + 1)), *from = malloc(sizeof(int) * (number + 1));
    memset(minSteps, 0, sizeof(int) * (number + 1));
    minSteps[1] = 0;

    for (int i = 1; i <= number; i++) {
        if (i + 1 <= number && (minSteps[i + 1] == 0 || minSteps[i + 1] > minSteps[i] + 1)) { 
            minSteps[i + 1] = minSteps[i] + 1;
            from[i + 1] = i;
        }
        if (i * 2 <= number && (minSteps[i * 2] == 0 || minSteps[i * 2] > minSteps[i] + 1)) {
            minSteps[i * 2] = minSteps[i] + 1;
            from[i * 2] = i;
        }
        if (i * 3 <= number && (minSteps[i * 3] == 0 || minSteps[i * 3] > minSteps[i] + 1)) {
            minSteps[i * 3] = minSteps[i] + 1;
            from[i * 3] = i;
        }
    }

    printf("%d\n", minSteps[number]);

    int path[minSteps[number] + 1];
    int current = from[number]; 
    path[minSteps[number]] = number;    
    for (int i = minSteps[number] - 1; i >= 0; i--) {
        path[i] = current;
        current = from[current];
    }

    for (int i = 0; i <= minSteps[number]; i++)
        printf("%d ", path[i]);
    printf("\n");

    free(minSteps);
    free(from);
}

int min(int a, int b, int c) {
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}