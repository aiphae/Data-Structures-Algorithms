#include <stdio.h>

int minCoinsNumber(int amount);
int min(int a, int b, int c);

int main(void) {
    int amount;
    scanf("%d", &amount);

    printf("%d\n", minCoinsNumber(amount));
}

int minCoinsNumber(int amount) {
    int coins[amount + 1];
    coins[0] = 0;
    coins[1] = 1;
    coins[2] = 2;
    coins[3] = 1;
    coins[4] = 1;

    for (int i = 5; i <= amount; i++)
        coins[i] = min(coins[i - 1] + 1, coins[i - 3] + 1, coins[i - 4] + 1);
    
    return coins[amount];
}

int min(int a, int b, int c) {
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}