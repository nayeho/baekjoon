#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int result = 2;
    
    for(int i = 0; i < N; i++)
    {
        result = result * 2 - 1;
    }

    printf("%d", result * result);
    return 0;
}