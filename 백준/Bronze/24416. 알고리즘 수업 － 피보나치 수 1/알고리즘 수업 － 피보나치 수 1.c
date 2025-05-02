#include <stdio.h>

int count_fib = 0;
int count_fibonacci = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        count_fib++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{
    int f[41] = { 0, };
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) 
    {
        f[i] = f[i - 1] + f[i - 2];
        count_fibonacci++;
    }
    return f[n];
}

int main(void)
{
    int n;
    scanf("%d", &n);

    fib(n);
    fibonacci(n);
    printf("%d %d\n", count_fib, count_fibonacci);

    return 0;
}