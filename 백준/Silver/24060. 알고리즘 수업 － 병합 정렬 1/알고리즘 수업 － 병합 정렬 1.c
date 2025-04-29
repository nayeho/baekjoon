#include <stdio.h>
#include <stdlib.h>

#define MAX 500001

int A[MAX], tmp[MAX];
int count = 0;
int result = -1;
int K;

void merge(int p, int q, int r)
{
    int i = p, j = q + 1, t = 0;

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }

    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];

    i = p; t = 0;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        count++;
        if (count == K) result = A[i - 1];
    }
}

void merge_sort(int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main(void)
{
    int N;
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    merge_sort(0, N - 1);

    printf("%d\n", result);

    return 0;
}