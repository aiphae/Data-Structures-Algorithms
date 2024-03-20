#include <stdio.h>

int fibonacci(int number);
int fib_last_digit(int number, int digitsArray[]);

int main(void) {
    long long int fibonacciArray[60]; int a;

    fibonacciArray[0] = 0;
    fibonacciArray[1] = 1;
    for (int i = 2; i < 60; i++) {
        fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
    }

    for (int i = 0; i < 60; i++) {
        fibonacciArray[i] = fibonacciArray[i] % 10;
    }    

    scanf("%d", &a);
    printf("%lld\n", fibonacciArray[a % 60]);
}

int fibonacci(int number) {

}

int fib_last_digit(int number, int digitsArray[]) {
    return digitsArray[number % 60];
}