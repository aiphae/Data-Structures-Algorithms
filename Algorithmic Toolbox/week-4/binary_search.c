#include <stdio.h>

int binary_search(int array[], int lower, int upper, int number);

int main(void) {
    int amount;
    scanf("%d", &amount);
    int numbers[amount];
    for (int i = 0; i < amount; i++)
        scanf("%d", &numbers[i]);

    int amountToSearch;
    scanf("%d", &amountToSearch);
    int numbersToSearch[amountToSearch];
    for (int i = 0; i < amountToSearch; i++)
        scanf("%d", &numbersToSearch[i]);    

    int index;
    for (int i = 0; i < amountToSearch; i++) {
        index = binary_search(numbers, 0, amount, numbersToSearch[i]);
        if (index == -1) printf("-1 ");
        else printf("%d ", index);
    }
    printf("\n");
}

int binary_search(int array[], int lower, int upper, int number) {
    if (upper < lower) return -1;

    int mid = (lower + (upper - lower) / 2);

    if (array[mid] == number) return mid;
    else if (number < array[mid]) return binary_search(array, lower, mid - 1, number);
    else return binary_search(array, mid + 1, upper, number);
}