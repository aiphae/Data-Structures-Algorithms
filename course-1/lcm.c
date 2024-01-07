#include <stdio.h>

long long int lcm(int a, int b);
int gcd(int a, int b);

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%lld\n", lcm(a, b));
}

long long int lcm(int a, int b) {
    long long int result = (long long int) a * (b / gcd(a, b));
    return result;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}