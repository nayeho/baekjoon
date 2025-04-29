/*
    최종적으로 시간초과가 발생했다.
    물론 C언어로 해결할 수 있는 방법이 있겠지만
    좀 더 빠른 소수 판별 로직을 전개해보자
    1. 모든 n에 대해 약수인지 판별
    2. n/2까지만 판별
    3. Sieve of Eratosthenes(에라토스테네스의 체)
      - (root(n)) 이하 판별
    4. Trial division
      - 3번에서 홀수만 검사
    까지도 시간초과가 발생했다면
    5. Miller-Rabin 알고리즘을 사용해보자
*/

/* 아래는 시간초과 발생한 4번까지의 로직이다.
// 시간초과 발생했으므로
// 짝수는 건너뛰고 검사해보자.

int is_prime(int n)
{
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    int root = (int)sqrt(n);
    for (int i = 3; i <= root; i += 2)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int next_prime(int n)
{
    if (n <= 2) return 2;
    // 2이상의 소수는 존재하지 않으므로
    // 짝수면 while을 검사할 필요가 없다.
    if (n % 2 == 0) n++;

    while (1)
    {
        // 짝수는 검사하지 않는다.
        if (is_prime(n)) return n;
        if (n % 2 == 0) n++;
        else n += 2;
    }
}
*/

#include <stdio.h>

// 계속 사용할 자료형을 짧게 재정의하자
typedef unsigned long long ull;

// (a * b) % mod을 안전하게 계산
// a * b를 직접 곱하면 overflow 발생할 수 있으므로
// 비트 연산으로 a를 하나씩 더하면서 처리하자
ull mulmod(ull a, ull b, ull mod)
{
    ull result = 0;
    a = a % mod;
    while (b > 0)
    {
        // 만약, b가 홀수라면 result에 a를 추가
        if (b & 1) result = (result + a) % mod;
        // a를 2배로 증가
        a = (a << 1) % mod;
        // b를 절반으로 진행
        b >>= 1;
    }
    return result;
}

// (base^exp) % mod를 빠르게 계산
ull powmod(ull base, ull exp, ull mod)
{
    ull result = 1;
    base = base % mod;
    while (exp > 0)
    {
        // 현재 비트가 1이면 result에 곱하자
        if (exp & 1) result = mulmod(result, base, mod);
        // 제곱을 base에 담기
        base = mulmod(base, base, mod);
        // 지수를 절반으로 진행
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin test
// 주어진 base a를 활용해 n이 소수인지 확률적으로 확인
// 확률적 <- 중요한 키워드
int miller_rabin(ull n, ull a)
{
    // a로 나누어 떨어지면 소수가 아님(합성수)
    if (n % a == 0) return 0;

    // n - 1 벽부터
    // 2로 나누어 가면서 나누어 떨어지지 않을 때까지 나눔
    // -> 예쁘게 표현하면 2의 거듭제곱으로 분해
    ull d = n - 1;
    while (d % 2 == 0) d /= 2;

    // (a^d) mod n 계산
    ull t = powmod(a, d, n);
    
    // 중요 포인트
    // n이 소수라면
    // - 어떤 정수 a에 대해서
    // ≡ (ㄷ한자 활용한 특수문자인데 유니코드 통과 가능한지 확인)
    // (a^d) ≡ (mod n) 이거나 (a^{2^r * d} ≡ (mod n))인 r이 존재하여야 한다
    // n - 1 = 2^k * d (d는 홀수)
    // n - 1을 2의 거듭제곱과 홀수로 분리해서
    // (a^d) % n == 1 혹은 (a^(2^r * d)) % n == n - 1 (단, r >= 0)
    // 까지 통과한다면 n은 소수일 확률이 있다
    
    // 둘 중 하나라도 만족한다면
    // 우리에게 주어진 a는 합성수라고 확실히 단정할 수 없다
    if (t == 1 || t == n - 1) return 1;

    // n이 소수면 a를 d번 거듭제곱하면 1이나 n - 1이 나와야 한다
    // 만약, 1이나 n - 1이 나오면 소수일 확률이 높다(확정은 아님)
    // 만약, 둘 다 아니면 소수 아님(합성수 확정)
    while (d != n - 1)
    {
        t = mulmod(t, t, n);
        d *= 2;
        if (t == n - 1) return 1;
    }
    return 0;
}

int is_prime(ull n)
{
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;

    // Miller-Rabin 베이스: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
    // 판별할 수 n의 크기가 작을 경우, 작은 수의 a에 대해서만 검사해보면
    // 결정론적으로 소수를 판별할 수 있다
    // 여기서 충분은 100% 판별 가능함을 말한다
    // n < 1,373,653일 경우 a = 2, 3에 대해 검사하면 충분
    // n < 9,080,191일 경우 a = 31, 73에 대해 검사하면 충분
    // n < 4,759,123,141일 경우 a = 2, 7, 61에 대해 검사하면 충분
    // n < 2,152,302,898,747일 경우 a = 2, 3, 5, 7, 11에 대해 검사하면 충분
    // n < 3,474,749,660,383일 경우 a = 2, 3, 5, 7, 11, 13에 대해 검사하면 충분
    // n < 341,550,071,728,321일 경우 a = 2, 3, 5, 7, 11, 13, 17에 대해 검사하면 충분
    // 결론적으로 정리하면 unsigned long long 범위에서는
    // 37이하의 소수를 이용해 테스트를 통과하면 100% 소수이다
    
    ull bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int num_bases = sizeof(bases) / sizeof(bases[0]);

    for (int i = 0; i < num_bases; i++)
    {
        // 작은 수에 대해 불필요한 검사를 건너뛰자
        if (bases[i] >= n) break;
        // 하나라도 실패하면 합성수!
        // 다 통과하면 소수일 확률이 높음
        if (!miller_rabin(n, bases[i])) return 0;
    }
    return 1;
}

ull next_prime(ull n)
{
    if (n <= 2) return 2;
    if (n % 2 == 0) n++;

    while (1)
    {
        if (is_prime(n)) return n;
        n += 2;
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        ull n;
        scanf("%llu", &n);
        printf("%llu\n", next_prime(n));
    }
    return 0;
}