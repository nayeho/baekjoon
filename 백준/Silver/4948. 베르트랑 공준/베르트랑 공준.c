#include <stdio.h>

#define MAX 246913  // 2 * 123456 + 1

char is_prime[MAX];

// 범위가 충분히 작아 에라토스테네스의 체로 구하자
// 체로 걸러진 합성수들은 0을 집어 놓고
// 안 걸러진 소수들은 요소가 1이 된다
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
    // 에라토스테네스의 체로 미리 is_prime 배열 채워 넣기
    sieve();

    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int count = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            // is_prime은 소수라면 1, 합성수라면 0이 담겨 있다
            if (is_prime[i]) count++;
        }
        printf("%d\n", count);
    }

    return 0;
}