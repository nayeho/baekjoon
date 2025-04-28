#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// 유클리드 호제법
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int *tree = malloc(sizeof(int) * N);
    if (tree == NULL) return 1;

    for (int i = 0; i < N; i++) scanf("%d", &tree[i]);

    // 모든 가로수 간격을 일정하게 나눌 수 있는 최소 공통 간격을 구하기 위해
    // 인접한 두 나무 사이의 거리 차를 모아
    // 그 거리의 차들의 최대 공약수를 구하자
    int dist_gcd = tree[1] - tree[0];
    for (int i = 1; i < N - 1; i++)
    {
        int diff = tree[i + 1] - tree[i];
        dist_gcd = gcd(dist_gcd, diff);
    }

    
    // tree[i]가 4
    // tree[i + 1]이 10이고
    // dist_gcd가 2라면 -> 심어야 하는 간격이 2라면
    // ((10 - 4) / 2) - 1
    // ((tree[i + 1] - tree[i]) / 2) - 1 
    // 만큼 심어야 한다
    int result = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int diff = tree[i + 1] - tree[i];
        result += diff / dist_gcd - 1;
    }

    printf("%d\n", result);

    free(tree);
    return 0;
}