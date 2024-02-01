#include <stdio.h>

int lcs(int seq1[], int seq2[]);

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

    printf("%d\n", lcs(seq1, seq2));
}

int lcs(int seq1[], int seq2[]) {
    
}