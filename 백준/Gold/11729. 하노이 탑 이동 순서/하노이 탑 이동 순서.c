#include <stdio.h>

// n개를 from에서 to로 옮기기
// 보조는 aux
void hanoi(int n, int from, int aux, int to)
{
    if (n == 1)
    {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, to, aux);
    // 실제 이동 경로
    printf("%d %d\n", from, to);
    hanoi(n - 1, aux, from, to);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    // 보편적으로 계산할 수 있는
    // 이동 횟수는 2^N - 1 이다
    printf("%d\n", (1 << N) - 1);
    hanoi(N, 1, 2, 3);

    return 0;
}