#include <stdio.h>

#define MAX 9

int sequence[MAX]; // 선택한 수열 저장
int used[MAX];     // 중복 방지 체크

// 현재 깊이 depth
void backtrack(int depth, int N, int M)
{
    // 수열 길이 M이 되면 출력
    if (depth == M)
    {
        for (int i = 0; i < M; i++) printf("%d ", sequence[i]);
        printf("\n");
        return;
    }

    // 1부터 N까지 순회 (사전순)
    for (int i = 1; i <= N; i++)
    {
        if (!used[i])
        {
            used[i] = 1;              // 사용 표시
            sequence[depth] = i;      // 수열에 기록
            backtrack(depth + 1, N, M);     // 다음 단계로
            used[i] = 0;              // 되돌리기 (backtrack)
        }
    }
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    backtrack(0, N, M);
    return 0;
}