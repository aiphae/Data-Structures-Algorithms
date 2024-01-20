#include <stdio.h>

void print_array(int array[], int length);
void bubble_sort(int array[], int length);

int main(void) {
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++)
        scanf("%d", &array[i]);

    printf("Initial array: ");
    print_array(array, number);

    bubble_sort(array, number);

    printf("Sorted by bubble sort algorithm: ");
    print_array(array, number);
}

void bubble_sort(int array[], int length) {
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}