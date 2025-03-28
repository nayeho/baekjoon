#include <stdio.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    char board[51][51];
    for(int i = 0; i < N; i++)
    {
        scanf("%s", board[i]);
    }
    int result = 64; // 모두 칠하는 경우의 수
    
    // 8x8로 자르기
    for(int i = 0; i < N - 7; i++)
    {
        for(int j = 0; j < M - 7; j++)
        {
            // 첫 번째 i,j가 0,0이라고 가정
            // 0,0이 W라면 0,2, 0,4, ..., 7,7까지 W여야 한다
            // i + j가 짝수, 홀수인지 구분해서 진행하자
            
            // 0,0이 W라면
            // 짝수 -> W
            // 홀수 -> B
            // 이게 성립되지 않으면 칠하는 개수를 하나 늘리자
            
            int minW = 0; // 시작이 W일때 칠하는 횟수
            int minB = 0; // 시작이 B일때 칠하는 횟수
            
            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    // 현재 위치의 색상
                    char color = board[i + x][j + y];
                    
                    // 짝수라면 0,0과 색이 일치해야 함
                    if((x + y) % 2 == 0)
                    {
                        if(color == 'W') minB++;
                        if(color == 'B') minW++;
                    }
                    else
                    {
                        if(color == 'W') minW++;
                        if(color == 'B') minB++;
                    }
                }
            }
             // 더 작은 쪽을 이번 8x8에서 칠해야 하는 횟수로 규정
            int min = minW < minB ? minW : minB;
            
            // 이번 8x8보드에서 규정된 min이 result보다 작으면 갱신
            result = min < result ? min : result;
            
            
        }
    }
    
    printf("%d", result);
    return 0;
}