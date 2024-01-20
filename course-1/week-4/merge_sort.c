#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int length);
void merge_sort(int array[], int left, int right);
void merge(int array[], int left, int middle, int right);

int main(void) {
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++)
        scanf("%d", &array[i]);
        
    merge_sort(array, 0, number - 1);
    print_array(array, number);
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge_sort(int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void merge(int array[], int left, int middle, int right) {
    int length1 = middle - left + 1, length2 = right - middle;
    int temp1[length1], temp2[length2];
    for (int i = 0; i < length1; i++)
        temp1[i] = array[left + i];
    for (int i = 0; i < length2; i++)
        temp2[i] = array[middle + 1 + i];

    for (int sub1 = 0, sub2 = 0, count = left; count <= right; count++) {
        if ((sub1 < length1) && (sub2 >= length2 || temp1[sub1] <= temp2[sub2])) {
            array[count] = temp1[sub1];
            sub1++;
        }
        else {
            array[count] = temp2[sub2];
            sub2++;
        }
    }
}