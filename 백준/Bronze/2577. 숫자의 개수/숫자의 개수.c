#include <stdio.h>

int main(void)
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    
    int result = A * B * C;
    int digit[10] = {0, };
    
    while(result)
    {
        digit[result % 10]++;
        result /= 10;
    }
    
    for(int i = 0; i < 10; i++) printf("%d\n", digit[i]);
    
    return 0;
}