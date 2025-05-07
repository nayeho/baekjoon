#include <stdio.h>

int main(void)
{
    // 최소 동전의 문제
    int N, K;
    scanf("%d %d", &N, &K);
    
    int array[N];
    
    for(int i = 0; i < N; i++) scanf("%d", &array[i]);
    
    int result = 0;
    
    for(int i = 0; i < N; i++)
    {
        int count = K / array[N - 1 - i];
        if(count > 0)
        {
            result += count;
            K %= array[N - 1 - i];
        }
    }    
    printf("%d\n", result);
    
    return 0;
}