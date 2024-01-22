#include <stdio.h>
#include <stdlib.h>

int merge_sort(int array[], int left, int right);
int merge(int array[], int left, int middle, int right);

int main(void) {
    int number;
    scanf("%d", &number);
    int array[number];
    for (int i = 0; i < number; i++)
        scanf("%d", &array[i]);
    
    int inversions = 0;
    inversions = merge_sort(array, 0, number - 1);

    printf("%d\n", inversions);
}


int merge_sort(int array[], int left, int right) {
    int inversions = 0;
    if (left < right) {
        int middle = left + (right - left) / 2;
        inversions += merge_sort(array, left, middle);
        inversions += merge_sort(array, middle + 1, right);
        inversions += merge(array, left, middle, right);
    }

    return inversions;
}

int merge(int array[], int left, int middle, int right) {
    int length1 = middle - left + 1, length2 = right - middle, inversions = 0;
    int temp1[length1], temp2[length2];
    for (int i = 0; i < length1; i++)
        temp1[i] = array[left + i];
    for (int i = 0; i < length2; i++)
        temp2[i] = array[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < length1 && j < length2) {
        if (temp1[i] <= temp2[j]) {
            array[k++] = temp1[i++];
        }
        else {
            array[k++] = temp2[j++];
            inversions += (length1 - i);
        }
    }

    while (i < length1) {
        array[k++] = temp1[i++];
    }
    while (j < length2) {
        array[k++] = temp2[j++];
    }

    return inversions;
}