#include <stdio.h>

#define MAX 1025

int array[MAX][MAX];
int sum[MAX][MAX];  // 누적합 배열

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) scanf("%d", &array[i][j]);

    // 2차원 누적합 계산
    // 1 2 3 4
    // 2 3 4 5
    // 3 4 5 6
    // 4 5 6 7
    // 만약, array[3][2] = 6까지의 누적합을 계산하려면
    // sum[2][2] + sum[3][1] 까지하면
    // 중복 영역이 발생한다. -> 빼주자 (-sum[2][1])
    // 그 후, array[i][j]를 더해주면 2차원 누적합 완성!
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + array[i][j];
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // 누적합을 이용한 구간합 계산
        int result = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

        printf("%d\n", result);
    }

    return 0;
}