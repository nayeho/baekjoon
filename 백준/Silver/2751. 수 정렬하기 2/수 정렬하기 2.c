// 내장된 qsort를 활용하려 했으나
// 최악인 경우 O(n^2)이 발생하여 런타임 에러가 나는 것으로 보임
// merge sort를 사용하자
#if 0
#include <stdio.h>
#include <stdlib.h>

// 내장 퀵정렬에 사용되는 비교 함수
int compare(const void *first, const void *second)
{
    int num1 = *(int *)first;
    int num2 = *(int *)second;

    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

int main()
{
    int N;
    
    // 입력이 잘못되었거나 0 이하일 경우
    if (scanf("%d", &N) != 1 || N < 1) { return 0; }

    // 정적 배열 선언 -> 런타임 에러
    // 그렇다면 동적 배열 선언해보자
    int *num = (int *)malloc(N * sizeof(int));
    if (num == NULL) { return 0; } // 동적 메모리 할당 실패
    
    for (int i = 0; i < N; i++)
    {
        // 입력 실패 시 리소스 해제 후 종료
        if (scanf("%d", &num[i]) != 1)
        {
            free(num);
            return 0;
        }
    }

    qsort(num, N, sizeof(int), compare); // (정렬할 배열, 요소 개수, 요소 크기, 비교 함수)

    for (int i = 0; i < N; i++) printf("%d\n", num[i]);

    free(num); // 동적 메모리 반환
    
    return 0;
}
#endif

// merge sort 전개
#include <stdio.h>
#include <stdlib.h>

void merge(int* array, int* temp, int left, int mid, int right)
{
    int i = left;     // 왼쪽 부분 배열 시작
    int j = mid + 1;  // 오른쪽 부분 배열 시작
    int k = left;     // 결과를 저장할 위치

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j]) temp[k++] = array[i++];
        else temp[k++] = array[j++];
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int i = left; i <= right; i++) array[i] = temp[i]; // 원본에 복사
}

void merge_sort(int* array, int* temp, int left, int right)
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

    int* array = malloc(sizeof(int) * N);
    int* temp = malloc(sizeof(int) * N);
    if(array == NULL) return 1;
    if(temp == NULL) return 1;
    
    for (int i = 0; i < N; i++) scanf("%d", &array[i]);

    // (정렬할 배열, 임시 저장 배열, 시작 인덱스, 끝 인덱스)
    merge_sort(array, temp, 0, N - 1);

    for (int i = 0; i < N; i++) printf("%d\n", array[i]);

    free(array);
    free(temp);
    
    return 0;
}
