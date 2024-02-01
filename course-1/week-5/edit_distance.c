#include <stdio.h>
#include <string.h>

int edit_distance(char str1[], char str2[]);
int min(int a, int b, int c);

int main(void) {
    char str1[100], str2[100];
    scanf("%s", str1);
    fflush(stdin);
    scanf("%s", str2);
    
    printf("%d\n", edit_distance(str1, str2));
}

int edit_distance(char str1[], char str2[]) {
    int length1 = strlen(str1), length2 = strlen(str2);
    int matrix[length1 + 1][length2 + 1];

    memset(matrix, 0, (length1 + 1) * (length2 + 1) * sizeof(int));

    for (int i = 0; i < length1 + 1; i++)
        matrix[i][0] = i;

    for (int i = 0; i < length2 + 1; i++)
        matrix[0][i] = i;

    int substitutionCost;
    for (int j = 1; j < length2 + 1; j++) {
        for (int i = 1; i < length1 + 1; i++) {
            substitutionCost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + substitutionCost);
        }
    }

    return matrix[length1][length2];
}

int min(int a, int b, int c) {
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}