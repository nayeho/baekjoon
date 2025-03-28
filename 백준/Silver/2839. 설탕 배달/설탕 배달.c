#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    
    // 3킬로그램 x봉지
    // 5킬로그램 y봉지
    // 3x + 5y = N
    // x + y = result
    
    // N이 18이라면
    // 일단 y에 3을 넣자. 4를 넣으면 무게를 넘는다
    // 남은 N이 3으로 나누어 떨어지면 끝
    // 아니라면 y를 하나 줄여 2를 넣자 -> 반복
    
    int result = -1;
    for(int i = N / 5; i >= 0; i--)
    {
        int remain = N - (i * 5);
        if(remain % 3 == 0)
        {
            result = i + (remain / 3);
            break;
        }
    }
    
    printf("%d", result);
    return 0;
}