#include <stdio.h>

#define MAX 100001

int array[MAX];
int prefix[MAX];  // 누적합 배열

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    // 입력과 동시에 누적합 계산
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &array[i]);
        prefix[i] = prefix[i - 1] + array[i];
    }

    int start, end;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &start, &end);

        // 구간합 = prefix[end] - prefix[start - 1]
        printf("%d\n", prefix[end] - prefix[start - 1]);
    }

    return 0;
}