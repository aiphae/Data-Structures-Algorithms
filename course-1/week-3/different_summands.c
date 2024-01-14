#include <stdio.h>
#include <math.h>

void summands(int number);

int main(void) {
    int number;
    scanf("%d", &number);

    summands(number);
}

void summands(int number) {
    float mainPart = (sqrt(8 * number + 1) - 1) / 2;
    int restPart = 0;
    if (floor(mainPart) != mainPart) restPart++;
    mainPart = floor(mainPart);
    printf("%d\n", (int) mainPart);

    for (int i = 1; i < mainPart; i++) {
        printf("%d ", i);
    }
    printf("%d", (int) (number - (mainPart * (mainPart - 1) / 2)));
    printf("\n");
}