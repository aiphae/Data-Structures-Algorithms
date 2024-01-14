#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void largestConcatenate(int array[], int number);

int main(void) {
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++) {
        scanf("%d", &array[i]);
    }
    
    largestConcatenate(array, number);
}

void largestConcatenate(int array[], int number) {
    int index;
    char ab[9], ba[9];
    for (int i = 0; i < number - 1; i++) {
        index = i;
        for (int j = i + 1; j < number; j++) {
            sprintf(ab, "%d%d", array[i], array[j]);
            sprintf(ba, "%d%d", array[j], array[i]);
            if (strcmp(ab, ba) < 0) {
                index = j;
            }
        }

        if (index != i) {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }

    for (int i = 0; i < number; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}