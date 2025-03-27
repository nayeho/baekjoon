#include <stdio.h>

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    
    int count = 0;
    
    // 절반만 판별하자
    for(int i = 1; i <= (int)(N / 2); i++)
    {
        if(N % i == 0) count++;
        if(K == count)
        {
            printf("%d", i);
            break;
        }
    }
    // N도 N의 약수이므로 마지막 확인
    count++;
    if(K == count) printf("%d", N);
    else if(K > count) printf("%d", 0);
    
    return 0;
}