#include <stdio.h>

int minimumStops(int distance, int maxMileage, int gasStations[], int amountOfGasStations);

int main(void) {
    int distance, maxMileage, amountOfGasStations;
    scanf("%d", &distance);
    fflush(stdin);
    scanf("%d", &maxMileage);
    fflush(stdin);
    scanf("%d", &amountOfGasStations);
    int gasStations[amountOfGasStations];
    for (int i = 0; i < amountOfGasStations; i++) {
        scanf("%d", &gasStations[i]);
    }

    printf("%d\n", minimumStops(distance, maxMileage, gasStations, amountOfGasStations));
}

int minimumStops(int distance, int maxMileage, int gasStations[], int amountOfGasStations) {
    if (distance < maxMileage) {
        return 0;
    }

    int count = 0, limit = maxMileage, currentGasStation = 0;
    while (limit < distance) {
        if (gasStations[currentGasStation] > limit) return -1;

        while (currentGasStation < amountOfGasStations - 1 && gasStations[currentGasStation + 1] <= limit) {
            currentGasStation++;
        }

        count++;
        limit = gasStations[currentGasStation] + maxMileage;
        currentGasStation++;
    }

    return count;
}