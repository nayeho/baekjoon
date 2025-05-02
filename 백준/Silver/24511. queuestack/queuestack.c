#include <stdio.h>

#define MAX 100000

int main(void)
{
    int A;
    scanf("%d", &A);

    int B[MAX];
    int C[MAX];

    for (int i = 0; i < A; i++) scanf("%d", &B[i]);
    for (int i = 0; i < A; i++) scanf("%d", &C[i]);

    int count;
    scanf("%d", &count);

    for (int i = A - 1; count > 0 && i >= 0; i--)
        if (B[i] == 0)
        {
            printf("%d", C[i]);
            count--;
            if (count > 0) printf(" ");
        }

    while(count > 0)
    {
        int input;
        scanf("%d", &input);
        printf("%d", input);
        if (count > 1) printf(" ");
        count--;
    }

    printf("\n");
    return 0;
}