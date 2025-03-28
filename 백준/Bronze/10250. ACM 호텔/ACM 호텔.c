#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    

    for(int i = 0; i < T; i++)
    {
        int H, W, N;
        scanf("%d %d %d", &H, &W, &N);
        // H : 6, W : 12, N : 10
        // 6 x 12 행렬의 10번째 요소
        // 10 / 6 -> 1 (row가 1)
        // 10 % 6 -> 4 (col이 4)
        int ho = (N - 1) / H + 1;
        int stair = (N % H == 0) ? H : N % H; 

        printf("%d%02d\n", stair, ho);
    }
    
    return 0;
}