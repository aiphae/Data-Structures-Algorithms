#include <stdarg.h>
#include <stdio.h>

double min(int number, ...);

int main(void) {
    printf("%f\n", min(3, -3335.0, 2.0, -111.0));
}

double min(int number, ...) {
    va_list ptr;
    va_start(ptr, number);
    double min = va_arg(ptr, double);
    for (int i = 0; i < number - 1; i++) {
        double temp = va_arg(ptr, double);
        min = temp < min ? temp : min;
    }

    va_end(ptr);
    return min;
}