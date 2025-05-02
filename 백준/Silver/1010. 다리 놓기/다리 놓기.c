#include <stdio.h>

typedef unsigned long long ull;

ull combination(int n, int r) {
    // nCr == nC(n - r) 이므로 최소값 사용
    if (r > n - r) r = n - r;

    ull result = 1;
    for (int i = 1; i <= r; i++)
    {
        // 매번 나눠서 overflow 방지
        result *= (n - r + i);
        result /= i;
    }
    return result;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        // 동쪽(M)에서 서쪽(N)개를 택하는 경우의 수
        // 즉, MCN을 구하면 된다
        // 한 번 구하므로, 함수 없이 그냥 구하고 싶지만
        // overflow 발생 여지가 있으므로 함수로 진행해보자
    
        ull result = combination(M, N);
        printf("%llu\n", result);
    }
    return 0;
}