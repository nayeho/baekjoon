#include <stdio.h>

#define MAX 100000

int array[MAX];

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) scanf("%d", &array[i]);

    int sum = 0;

    // 첫 K일 합 초기화
    for (int i = 0; i < K; i++) sum += array[i];

    int max_sum = sum;

    // 슬라이딩 윈도우 시작
    // 앞에서 하나 빼고, 뒤에서 하나 더하기
    for (int i = K; i < N; i++)
    {
        sum = sum - array[i - K] + array[i];
        if (sum > max_sum) max_sum = sum;
    }

    printf("%d\n", max_sum);
    return 0;
}