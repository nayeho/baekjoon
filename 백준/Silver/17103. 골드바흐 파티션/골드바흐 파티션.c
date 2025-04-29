#include <stdio.h>

#define MAX 1000001  // 1,000,000까지

char is_prime[MAX];

// 에라토스테네스의 체를 사용하자
// 체 사용 추천 여부는 다음과 같이 판단해보자
// 10만 이하 -> 무조건 좋음
// 100만 이하 -> 매우 좋음 (메모리 1메가)
// 1000만 이하 -> 여전히 좋음 (메모리 10메가)
// 1억 이하 -> 여기서부터 밀러-라빈 알고리즘 고민 (메모리 100메가)
// 10억 이상 -> 불가능 (메모리 1기가 이상)

void sieve(void)
{
    for (int i = 0; i < MAX; i++) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i < MAX; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    // 소수 미리 구해놓기
    sieve();

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int count = 0;
        for (int i = 2; i <= N / 2; i++)
        {
            if (is_prime[i] && is_prime[N - i]) count++;
        }
        printf("%d\n", count);
    }

    return 0;
}