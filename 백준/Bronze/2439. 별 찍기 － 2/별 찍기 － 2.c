#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n - i; j++) printf("%s", " ");     
        for(int j = 0; j < i; j++) printf("%s", "*");
        printf("\n");
    }
    return 0;
}