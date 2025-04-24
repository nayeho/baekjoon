#include <stdio.h>
#include <stdlib.h>

#define MAX 10000001

// 상근이 카드 수 저장용 해시 테이블 (2배로 잡고, 음수 대응)
char *card_table;

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

    // (int *) -> (char *)
    // 값의 존재여부만 저장하면 되므로 1또는 0이 들어갈 예정
    // 즉, 메모리는 1byte씩 할당 되어도 충분
    card_table = (char *)calloc(MAX * 2, sizeof(char));
    if (card_table == NULL) return 1;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        // 그 카드 값에 대응하는 인덱스를 통해
        // card_table의 인덱스를 1로 설정
        // -> 1이면 해당 값이 존재
        // -> 0이면 해당 값 존재하지 않음
        card_table[to_index(num)] = 1;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &num);
        // 해당 값을 열었을 때, 1이라면 해당 값 존재
        if (card_table[to_index(num)] == 1) printf("1 ");
        else printf("0 ");
    }

    free(card_table);
    return 0;
}