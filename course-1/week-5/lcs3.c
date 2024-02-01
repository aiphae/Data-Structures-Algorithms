#include <stdio.h>
#include <string.h>

int lcs(int seq1[], int length1, int seq2[], int length2, int seq3[], int length3);
int max(int a, int b, int c);

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

    int length3;
    scanf("%d", &length3);
    int seq3[length3];
    for (int i = 0; i < length3; i++)
        scanf("%d", &seq3[i]);
    
    printf("%d\n", lcs(seq1, length1, seq2, length2, seq3, length3));
}

int lcs(int seq1[], int length1, int seq2[], int length2, int seq3[], int length3) {
    int matrix[length1 + 1][length2 + 1][length3 + 1];
    memset(matrix, 0, (length1 + 1) * (length2 + 1) * (length3 + 1) * sizeof(int));

    for (int i = length1 - 1; i > -1; i--) {
        for (int j = length2 - 1; j > -1; j--) {
            for (int k = length3 - 1; k > -1; k--) {
                if (seq1[i] == seq2[j] && seq2[j] == seq3[k])  {
                    matrix[i][j][k] = 1 + matrix[i + 1][j + 1][k + 1];
                }
                else {
                    matrix[i][j][k] = max(matrix[i][j + 1][k], matrix[i + 1][j][k], matrix[i][j][k + 1]);
                }
            }
        }
    }

    return matrix[0][0][0];
}

int max(int a, int b, int c) {
    int max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    return max;
}