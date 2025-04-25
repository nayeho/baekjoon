#include <stdio.h>
#include <stdlib.h>

#define MAX 10000001

// 상근이 카드 수 저장용 해시 테이블 (2배로 잡고, 음수 대응)
int *card_table;

// 배열 인덱스로 사용하기 위해 변환
// -10,000,000 ~ 0 ~ 10,000,000 범위의 값을
// 1 ~ 10,000,001 ~ 20,000,001 로 변환해 인덱스 사용

int to_index(int x)
{
    return x + MAX;
}

int main(void)
{
    int N, M, num;

    card_table = (int *)calloc(MAX * 2, sizeof(int));
    if (card_table == NULL) return 1;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        card_table[to_index(num)]++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        printf("%d ", card_table[to_index(num)]);
    }

    free(card_table);
    return 0;
}