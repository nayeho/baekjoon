#include <stdio.h>

#define MAX 100000

int A[MAX];
int temp[MAX];

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j]) temp[k++] = A[i++];
        else temp[k++] = A[j++];
    }

    while (i <= mid) temp[k++] = A[i++];
    while (j <= right) temp[k++] = A[j++];

    // 지역변수 i 그냥 쓰자
    for (int i = left; i <= right; i++) A[i] = temp[i];
}

void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int binary_search(int target, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (A[mid] == target) return 1;
        if (A[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return 0;
}

int main(void)
{
    int N, M;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    merge_sort(0, N - 1);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", binary_search(x, N));
    }

    return 0;
}