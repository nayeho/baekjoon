#include <stdio.h>

int main(void)
{
    // 모든 경우의 수 3중 for문
    int N, M;
    scanf("%d %d", &N, &M);
    
    int result = 0;
    
    int cards[N];
    for(int i = 0; i < N; i++) scanf("%d", &cards[i]);
    
    for(int i = 0; i < N - 2; i++)
    {
        for(int j = i + 1; j < N - 1; j++)
        {
            for(int k = j + 1; k < N; k++)
            {
                int sum = cards[i] + cards[j] + cards[k];
                if(sum <= M && sum > result) result = sum;
            }
        }
    }
    printf("%d", result);
    
    return 0;
}