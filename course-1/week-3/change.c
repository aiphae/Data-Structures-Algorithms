#include <stdio.h>

int change(int money);

int main(void) {
    int money;
    scanf("%d", &money);
    printf("%d\n", change(money));

}

int change(int money) {
    int count = 0;
    while (money > 0) {
        if (money - 10 >= 0) {
            count++;
            money -= 10;
        }
        else if (money - 5 >= 0) {
            count++;
            money -= 5;
        }
        else {
            count++;
            money--;
        }
    }

    return count;
}