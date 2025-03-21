#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int repeat = (int)(n / 4);
    
    for(int i = 0; i < repeat; i++)
    {
        printf("%s ", "long");
    }
    printf("%s", "int");
    
    return 0;
}