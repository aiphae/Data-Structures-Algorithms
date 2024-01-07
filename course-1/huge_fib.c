#include <stdio.h>

int pisano_period(int mod);
long int fibonacciMod(long long int a, int mod);

int main(void) {
    long long int a; int mod;
    scanf("%lld %d", &a, &mod);
    printf("%ld\n", fibonacciMod(a, mod));
}

int pisano_period(int mod) {
    long prev = 0, curr = 1, res = 0;
    for (int i = 0; i < mod * mod; i++) {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % mod;
        prev = temp;

        if (prev == 0 && curr == 1) {
            res = i + 1;
        }
    }

    return res;
}

long int fibonacciMod(long long int a, int mod) {
    int pisano = pisano_period(mod);
    a = a % pisano;
    long prev = 0, curr = 1;
    if (a == 0) {
        return 0;
    }
    else if (a == 1) {
        return 1;
    }

    for (int i = 0; i < a - 1; i++) {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % mod;
        prev = temp;
    }

    return curr % mod;
}