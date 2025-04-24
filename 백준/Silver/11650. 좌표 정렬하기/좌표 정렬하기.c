// 1.단 내장 퀵 정렬을 사용해보자 -> 런타임 에러나면 merge sort를 고려하자
// 또다시... 런타임 에러가 난다
// merge sort로 해결하자

#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Coord; // coordinate (좌표)



int compare(const void *first, const void *second)
{
    Coord c1 = *(Coord *)first;
    Coord c2 = *(Coord *)second;
    if(c1.x > c2.x) return 1;
    else if(c1.x == c2.x)
    {
        if(c1.y > c2.y) return 1;
        else return -1;
    }
    return -1;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    
    Coord array[N];
    
    for(int i = 0; i < N; i++) scanf("%d %d", &array[i].x, &array[i].y);

    qsort(array, N, sizeof(Coord), compare);
    
    for(int i = 0; i < N; i++) printf("%d %d\n", array[i].x, array[i].y);
    
    return 0;
}
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Coord;

void merge(Coord* array, Coord* temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        // x 기준 오름차순 → x 같으면 y 기준 오름차순
        if (array[i].x < array[j].x || (array[i].x == array[j].x && array[i].y <= array[j].y)) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int t = left; t <= right; t++) {
        array[t] = temp[t];
    }
}

void merge_sort(Coord* array, Coord* temp, int left, int right)
{
    if (left < right) {
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

    Coord* array = malloc(sizeof(Coord) * N);
    Coord* temp = malloc(sizeof(Coord) * N);
    
    if(array == NULL) return 1;
    if(temp == NULL) return 1;

    for (int i = 0; i < N; i++) scanf("%d %d", &array[i].x, &array[i].y);

    merge_sort(array, temp, 0, N - 1);

    for (int i = 0; i < N; i++) printf("%d %d\n", array[i].x, array[i].y);

    free(array);
    free(temp);
    return 0;
}

