#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define MAX_LEN 21

// 시간 초과 실패 -> 최악 case 복잡도 O(n^2) 나오는 것으로 보임
// 체이닝기반 해시셋으로 전개해보자 -> 시간 초과
// 정적 해시셋(Open Addressing 방식)으로 해결해보자 -> 시간 초과
// 문자열 자체를 저장보다 해시값을 저장하는 방식으로 전개해보자
// 전부 시간초과... 병합 정렬로 접근해보자

int total = 0;
int size = 0;

char array[MAX][MAX_LEN];
char buffer[MAX][MAX_LEN];
char input[MAX_LEN];

// 병합 정렬: 정렬된 두 배열을 병합
void merge_sort(char a[][MAX_LEN], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (strcmp(a[i], a[j]) <= 0) strcpy(buffer[k++], a[i++]);
        else strcpy(buffer[k++], a[j++]);
    }

    while (i <= mid) strcpy(buffer[k++], a[i++]);
    while (j <= right) strcpy(buffer[k++], a[j++]);

    // 지역변수 i 그냥 쓰자
    for (int i = left; i <= right; i++) strcpy(a[i], buffer[i]);
}

// 병합 정렬: 재귀 호출
void merge(char a[][MAX_LEN], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge(a, left, mid);
        merge(a, mid + 1, right);
        merge_sort(a, left, mid, right);
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    scanf("%s", input);

    for (int i = 1; i < N; i++)
    {
        scanf("%s", input);

        if (strcmp(input, "ENTER") != 0) strcpy(array[size++], input);
        if (i == N - 1 || strcmp(input, "ENTER") == 0)
        {
            if (size > 0)
            {
                merge(array, 0, size - 1);
                for (int j = 1; j <= size; j++)
                {
                    if (j == size || strcmp(array[j - 1], array[j]) != 0) total++;
                }
                size = 0;
            }
        }
    }

    printf("%d\n", total);
    return 0;
}