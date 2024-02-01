#include <stdio.h>

int ways(int number, int possibleSteps) {
    int ways[possibleSteps];
    ways[0] = 1;

    for (int i = 1; i <= number; i++) {
        for (int j = 1; j < possibleSteps; j++) {
            if (i - j < 0) continue;
            ways[i % possibleSteps] += ways[(i - j) % possibleSteps];
        }
    }

    return ways[number % possibleSteps];
}

int minCost(int number, int possibleSteps, int cost[]);
int min(int a, int b);

int main(void) {
    int number, possibleSteps;
    scanf("%d %d", &number, &possibleSteps);

    int cost[] = {0, 3, 2, 4};
    printf("%d\n", minCost(number, possibleSteps, cost));
}

int minCost(int number, int possibleSteps, int cost[]) {
    int minCost[number + 1];
    minCost[0] = 0;
    minCost[1] = cost[1];

    for (int i = 2; i <= number; i++)
        minCost[i] = cost[i] + min(minCost[i - 1], minCost[i - 2]);
    
    return minCost[number];
}   

int min(int a, int b) {
    return (a < b) ? a : b;
}