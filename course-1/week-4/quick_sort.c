#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int length);
void quick_sort(int array[], int lower, int upper);

int main(void) {
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++)
        scanf("%d", &array[i]);

    printf("Initial array: ");
    print_array(array, number);

    quick_sort(array, 0, number);

    printf("Sorted by quick sort algorithm: ");
    print_array(array, number);
}

void quick_sort(int array[], int lower, int upper) {
    if (upper <= lower) return;

    srand(time(NULL));
    int index = (rand() % (upper + 1 - lower)) + lower;
    int pivot = array[index];
    int temp, i, j;

    for (i = lower - 1, j = lower; j < index; j++) {
        if (array[j] < pivot) {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    i++;
    temp = array[i];
    array[i] = pivot;
    array[j] = temp;

    quick_sort(array, 0, i - 1);
    quick_sort(array, i + 1, upper);
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}