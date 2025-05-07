#include <stdio.h>

#define MAX 10000

long long lengths[MAX];

int main(void)
{
    int K, N;
    scanf("%d %d", &K, &N);

    long long max_length = 0;

    for (int i = 0; i < K; i++)
    {
        scanf("%lld", &lengths[i]);
        if (lengths[i] > max_length) max_length = lengths[i];
    }

    long long left = 1;
    long long right = max_length;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long count = 0;
        for (int i = 0; i < K; i++) count += lengths[i] / mid;

        if (count >= N)
        {
            answer = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    printf("%lld\n", answer);

    return 0;
}