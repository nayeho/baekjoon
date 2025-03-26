#include <stdio.h>

int abs(int a)
{
    return a < 0 ? -a : a;    
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n * 2 - 1; i++)
    {
        for(int j = 0; j < abs(n - 1 - i); j++) printf(" ");
        for(int j = 0; j < 2 * (n - abs(n - 1 - i)) - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}