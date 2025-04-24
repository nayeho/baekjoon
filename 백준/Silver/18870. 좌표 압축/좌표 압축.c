#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;         // 원래 값
    int loc;       // 입력된 순서
    int x_prime;   // 압축된 값
} Coord;

void merge(Coord *array, Coord *temp, int left, int mid, int right, int by_loc)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (by_loc == 0)
        {
            if (array[i].x <= array[j].x) temp[k++] = array[i++];
            else temp[k++] = array[j++];
        }
        else
        {
            if (array[i].loc <= array[j].loc) temp[k++] = array[i++];
            else temp[k++] = array[j++];
        }
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int i = left; i <= right; i++) array[i] = temp[i];
}

void merge_sort(Coord *array, Coord *temp, int left, int right, int by_loc)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, temp, left, mid, by_loc);
        merge_sort(array, temp, mid + 1, right, by_loc);
        merge(array, temp, left, mid, right, by_loc);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Coord *array = (Coord *)calloc(N, sizeof(Coord));
    Coord *temp = (Coord *)calloc(N, sizeof(Coord));
    
    if (array == NULL) return 1;
    if (temp == NULL) return 1;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i].x);
        array[i].loc = i;
    }

    // x 기준 정렬
    merge_sort(array, temp, 0, N - 1, 0);

    array[0].x_prime = 0;
    for (int i = 1; i < N; i++)
    {
        if (array[i].x == array[i - 1].x)
            array[i].x_prime = array[i - 1].x_prime;
        else
            array[i].x_prime = array[i - 1].x_prime + 1;
    }

    // loc 기준으로 원래 순서로 복구
    merge_sort(array, temp, 0, N - 1, 1);

    for (int i = 0; i < N; i++)
        printf("%d ", array[i].x_prime);

    free(array);
    free(temp);
    return 0;
}