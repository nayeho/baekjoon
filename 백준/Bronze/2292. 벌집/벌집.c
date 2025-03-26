#include <stdio.h>

int normal(int n)
{
    return (3 * n * n) - (3 * n) + 2;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    if(N == 1)
    {
        printf("%d", 1);
        return 0;
    }
    
    int weight = 2;
    while(1)
    {
        if(N < normal(weight)) break;
        weight++;
    }
    
    printf("%d", weight);
    return 0;
}