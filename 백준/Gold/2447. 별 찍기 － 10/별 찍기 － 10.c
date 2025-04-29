#include <stdio.h>

char map[2187][2187];  // 최대 3^7 = 2187

// x, y를 기준으로 n x n 영역을 모두 공백으로 채우자
void fill_blank(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            map[i][j] = ' ';
        }
    }
}

void draw_star(int x, int y, int n)
{
    // 1칸짜리 패턴이므로 *그리고 리턴
    if (n == 1)
    {
        map[x][y] = '*';
        return;
    }

    // 9개의 작은 블록으로 나누어서
    // 각각 fill_blank 혹은
    // draw_star 호출
    int size = n / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) fill_blank(x + size, y + size, size);
            else draw_star(x + i * size, y + j * size, size);
        }
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    draw_star(0, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", (map[i][j]));
        }
        printf("\n");
    }
    return 0;
}