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
        // array[i] >= array[j] : 내림차순
        // array[i] >= array[j] : 오름차순
        if (array[i] >= array[j]) temp[k++] = array[i++];
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
    int N, original;
    scanf("%d", &N);
    
    original = N; // 원본 보존
    
    int digits = 0;
    
    while(N > 0)
    {
        digits++;
        N /= 10;
    }

    int* array = malloc(sizeof(int) * digits);
    int* temp = malloc(sizeof(int) * digits);
    if(array == NULL) return 1;
    if(temp == NULL) return 1;
    
    N = original; // N 다시 복구
    
    for (int i = 0; i < digits; i++) 
    {
        array[i] = N % 10;
        N /= 10;
    }

    // (정렬할 배열, 임시 저장 배열, 시작 인덱스, 끝 인덱스)
    merge_sort(array, temp, 0, digits - 1);
    
    int result = 0;
    int pow = 1;
    for (int i = 0; i < digits; i++)
    {
        // 5 3 2 1
        result += array[digits - 1 - i] * pow;
        pow *= 10;
    }

    printf("%d\n", result);

    free(array);
    free(temp);
    
    return 0;
}