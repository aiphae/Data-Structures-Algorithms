#include <stdio.h>

int binary_search(int array[], int lower, int upper, int number);

int main(void) {
    int amount;
    printf("Amount of numbers: ");
    scanf("%d", &amount);
    int numbers[amount];
    printf("Enter numbers: ");
    for (int i = 0; i < amount; i++)
        scanf("%d", &numbers[i]);

    int numberToSearch;
    printf("Number to search: ");
    scanf("%d", &numberToSearch);

    int index = binary_search(numbers, 0, amount, numberToSearch);
    if (index == -1) printf("Not found\n");
    else printf("Found at index %d\n", index);
}

int binary_search(int array[], int lower, int upper, int number) {
    if (upper == lower) return -1;

    int mid = (lower + (upper - lower) / 2);

    if (array[mid] == number) return mid;
    else if (number < array[mid]) return binary_search(array, lower, mid - 1, number);
    else return binary_search(array, mid + 1, upper, number);
}