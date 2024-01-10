#include <stdio.h>

double maxCost(double valuePerMass[][2], double capacity, int compounds);

int main(void) {
    int compounds; double capacity;
    scanf("%d %lf", &compounds, &capacity);

    double valuePerMass[compounds][2];
    for (int i = 0; i < compounds; i++) {
        int cost; double weight;
        scanf("%d %lf", &cost, &weight);
        valuePerMass[i][0] = cost / weight;
        valuePerMass[i][1] = weight;
    }

    printf("%lf\n", maxCost(valuePerMass, capacity, compounds));
}

double maxCost(double valuePerMass[][2], double capacity, int compounds) {
    double cost = 0, maxValuePerMass = 0;
    int index = 0;
    while (capacity > 0) {
        maxValuePerMass = 0;
        for (int i = 0; i < compounds; i++) {
            if (valuePerMass[i][1] != -1) {
                if (valuePerMass[i][0] > maxValuePerMass) {
                    maxValuePerMass = valuePerMass[i][0];
                    index = i;
                }
            }
        }

        if (valuePerMass[index][1] <= capacity) {
            cost = cost + valuePerMass[index][0] * valuePerMass[index][1];
            capacity = capacity - valuePerMass[index][1];
        }
        else {
            cost = cost + valuePerMass[index][0] * capacity;
            capacity = 0;
        }
        valuePerMass[index][1] = -1;
    }

    return cost;
}