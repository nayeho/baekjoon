#include <stdio.h>

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    
    // N : 5, K : 2
    // 5C2
    // 5 x 4 / 2 x 1
    
    int molecule = 1;
    int denominator = 1;
    
    for(int i = 0; i < K; i++)
    {
        molecule *= N - i;
        denominator *= K - i;
    }
    printf("%d\n", molecule / denominator);
    
    return 0;
}