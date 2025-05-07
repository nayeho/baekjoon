#include <stdio.h>

#define MAX 9

int sequence[MAX];

void backtrack(int depth, int start, int N, int M)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++) printf("%d ", sequence[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= N; i++)
    {
        sequence[depth] = i;
        backtrack(depth + 1, i + 1, N, M);
    }
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    backtrack(0, 1, N, M);  // start는 항상 1부터 시작
    return 0;
}