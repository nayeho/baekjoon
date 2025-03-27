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
    int M, N;
    scanf("%d %d", &M, &N);
    
    int sum = 0;
    int check = 1;
    int min_prime_number = 0;
    for(int i = M; i <= N; i++)
    {
        // i가 소수인가?
        if(is_prime_number(i) == 1)
        {
            if(check == 1)
            {
                min_prime_number = i;
                check = 0;
            }
            sum += i;
        }
    }
    
    if(sum == 0) printf("%d", -1);
    else printf("%d\n%d", sum, min_prime_number);
    
    return 0;
}