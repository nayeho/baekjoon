#include <stdio.h>

int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
    
    int GCD, LCM;
    
    int min = A < B ? A : B;
    for(int i = 1; i <= min / 2; i++)
    {
        if(A % i == 0 && B % i == 0)
        {
            GCD = i;
        }
    }
    if(A % min == 0 && B % min == 0) GCD = min;
    
    // A = aG, B = bG, L = abG, LG = abG^2. = AB
    LCM = A * B / GCD;
    printf("%d\n%d", GCD, LCM);
    
    return 0;
}