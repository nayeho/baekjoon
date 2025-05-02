#include <stdio.h>

// 덩치가 영어로 big?
typedef struct Big
{
    int weight;
    int height;
} Big;

int main(void)
{
    int N;
    scanf("%d", &N);

    Big big[N];

    // 입력부
    for (int i = 0; i < N; i++) scanf("%d %d", &big[i].weight, &big[i].height);

    // 로직
    int rank; // 등수
    for (int i = 0; i < N; i++)
    {
        rank = 1; // 기본 등수는 1등

        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;

            // 나보다 몸무게, 키 둘 다 크면 등수 +1
            if (big[j].weight > big[i].weight && big[j].height > big[i].height) rank++;
        }

        printf("%d ", rank);
    }

    printf("\n");
    return 0;
}