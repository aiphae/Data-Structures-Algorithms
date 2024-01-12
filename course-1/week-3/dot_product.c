#include <stdio.h>

int maxDotProduct(int serie1[], int serie2[], int n, int processed);

int main(void) {
    int n;
    scanf("%d", &n);

    int serie1[n], serie2[n];
    for (int i = 0; i < n; i++) scanf("%d", &serie1[i]);
    for (int i = 0; i < n; i++) scanf("%d", &serie2[i]);

    printf("%d\n", maxDotProduct(serie1, serie2, n, 0));  
}

int maxDotProduct(int serie1[], int serie2[], int n, int processed) {
    if (processed == n) return 0;
    int maxNumber1 = 0, maxNumber2 = 0, index1 = 0, index2 = 0;
    for (int i = 0; i < n; i++) {
        if (serie1[i] > maxNumber1 && serie1[i] != -1) {
            maxNumber1 = serie1[i];
            index1 = i;
        }
        if (serie2[i] > maxNumber2 && serie2[i] != -1) {
            maxNumber2 = serie2[i];
            index2 = i;
        }
    }
    processed++;
    serie1[index1] = -1;
    serie2[index2] = -1;    

    return maxNumber1 * maxNumber2 + maxDotProduct(serie1, serie2, n, processed);
}