#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int age;
    char name[101]; // 이름의 최대 길이 100자
    int index;      // 가입 순서
} Member;

void merge(Member *array, Member *temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (array[i].age < array[j].age || (array[i].age == array[j].age && array[i].index < array[j].index))
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int i = left; i <= right; i++) array[i] = temp[i];
}

void merge_sort(Member *array, Member *temp, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, temp, left, mid);
        merge_sort(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Member *array = malloc(sizeof(Member) * N);
    Member *temp = malloc(sizeof(Member) * N);
    
    if (array == NULL) return 1;
    if (temp == NULL) return 1;

    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &array[i].age, array[i].name);
        array[i].index = i;
    }

    merge_sort(array, temp, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d %s\n", array[i].age, array[i].name);

    free(array);
    free(temp);
    return 0;
}
