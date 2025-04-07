#include <stdio.h>

int main(void)
{
    long long A, B;
    scanf("%lld %lld", &A, &B);

    long long result;
    long long multi_A_B = A * B;
    while(1)
    {
        if(B == 0)
        {
            printf("%lld", multi_A_B / A);
            break;
        }
        else
        {
            result = A % B;
            A = B;
            B = result;
        }
    }
    return 0;
}