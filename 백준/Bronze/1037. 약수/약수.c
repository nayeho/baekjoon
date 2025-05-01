#include <stdio.h>

int main(void)
{
    int min;
    int n;
    scanf("%d", &n);
    
    scanf("%d", &min);
    int max = min;
    
    for(int i = 0; i < n - 1; i++)
    {
        int input;
        scanf("%d", &input);
        if(input > max) max = input;
        if(input < min) min = input;
    }
    printf("%d\n", min * max);
    return 0;
}