#include <stdio.h>

long long factorial(int n)
{
    if (n <= 1) return 1;
    return (long long)n * factorial(n - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    printf("%lld\n", factorial(N));
    
    return 0;
}