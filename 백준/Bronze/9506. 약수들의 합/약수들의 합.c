#include <stdio.h>

int main(void)
{

    
    while(1)
    {
        int n;
        scanf("%d", &n);
        
        if(n == -1) break;
        
        int sum = 0;
        int divisor[10000];
        int len = 0;
        for(int i = 1; i <= (int)(n / 2); i++)
        {
            if(n % i == 0)
            {
                sum += i;
                divisor[len++] = i;
            } 
        }
        
        if(n == sum)
        {
            // 완전수
            printf("%d = ", n);
            for(int i = 0; i < len - 1; i++)
            {
                printf("%d + ", divisor[i]);
            }
            printf("%d\n", divisor[len - 1]);
        }
        else
        {
            // 완전수 아님
            printf("%d is NOT perfect.\n", n);
        }
    }
    
    return 0;
}