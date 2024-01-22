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

    srand(time(NULL));
    quick_sort(array, 0, number);

    print_array(array, number);
}

void quick_sort(int array[], int lower, int upper) {
    if (upper <= lower) return;

    int index = (rand() % (upper + 1 - lower)) + lower;
    int pivot = array[index];

    int less = lower, greater = upper - 1, i = lower, temp;
    while (i <= greater) {
        if (array[i] < pivot) {
            temp = array[less];
            array[less] = array[i];
            array[i] = temp;

            less++;
            i++;
        }
        else if (array[i] > pivot) {
            temp = array[greater]; 
            array[greater] = array[i];
            array[i] = temp;

            greater--;
        }
        else {
            i++;
        }
    }

    quick_sort(array, lower, less - 1);
    quick_sort(array, greater + 1, upper);
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}