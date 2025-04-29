#include <stdio.h>

long long fibonacci(int n)
{
    if (n == 0) return 0;
    if (n <= 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    printf("%lld\n", fibonacci(N));
    
    return 0;
}