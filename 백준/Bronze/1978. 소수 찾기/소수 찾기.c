#include <stdio.h>

int is_prime_number(int num)
{
    if (num < 2) return 0;
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);
        
        if(is_prime_number(input) == 1) count++;
    }
    printf("%d", count);
    
    return 0;
}