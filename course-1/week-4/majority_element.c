#include <stdio.h>

int majority_element(int numbers[], int lower, int upper);

int main(void) {
    int amount;
    scanf("%d", &amount);
    int numbers[amount];

    for (int i = 0; i < amount; i++)
        scanf("%d", &numbers[i]);

    int element = majority_element(numbers, 0, amount);
    if (element != -1) printf("1\n");
    else printf("0\n");
}

int majority_element(int numbers[], int lower, int upper) {
    if (lower >= upper) return numbers[lower];

    int mid = lower + (upper - lower) / 2;
    int left_majority_element = majority_element(numbers, lower, mid);
    int right_majority_element = majority_element(numbers, mid + 1, upper);

    if (left_majority_element == right_majority_element) return left_majority_element;

    int left_count = 0, right_count = 0;
    for (int i = lower; i < upper; i++) {
        if (numbers[i] == left_majority_element) left_count++;
        if (numbers[i] == right_majority_element) right_count++;
    }

    if (left_count > (upper - lower) / 2) return left_majority_element;
    if (right_count > (upper - lower) / 2) return right_majority_element;

    return -1;
}