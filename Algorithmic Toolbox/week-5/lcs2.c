#include <stdio.h>
#include <string.h>

int lcs(int seq1[], int length1, int seq2[], int length2);
int max(int a, int b);

int main(void) {
    int length1;
    scanf("%d", &length1);
    int seq1[length1];
    for (int i = 0; i < length1; i++)
        scanf("%d", &seq1[i]);
    
    int length2;
    scanf("%d", &length2);
    int seq2[length2];
    for (int i = 0; i < length2; i++)
        scanf("%d", &seq2[i]);

    printf("%d\n", lcs(seq1, length1, seq2, length2));
}

int lcs(int seq1[], int length1, int seq2[], int length2) {
    int matrix[length1 + 1][length2 + 1];
    memset(matrix, 0, (length1 + 1) * (length2 + 1) * sizeof(int));

    for (int i = length1 - 1; i > -1; i--) {
        for (int j = length2 - 1; j > -1; j--) {
            if (seq1[i] == seq2[j]) matrix[i][j] = 1 + matrix[i + 1][j + 1];
            else matrix[i][j] = max(matrix[i][j + 1], matrix[i + 1][j]);
        }
    }

    return matrix[0][0];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}