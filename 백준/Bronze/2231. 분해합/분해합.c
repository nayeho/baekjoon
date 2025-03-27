#include <stdio.h>

int function(int num)
{
    // 분해합이 영어로 뭐지?
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    for(int i = 1; i < N; i++)
    {
        if(N == function(i) + i)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", 0);
    
    return 0;
}