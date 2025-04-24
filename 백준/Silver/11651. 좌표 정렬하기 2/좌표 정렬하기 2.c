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
        // y 기준 오름차순 -> y 같으면 x 기준 오름차순
        if (array[i].y < array[j].y || (array[i].y == array[j].y && array[i].x <= array[j].x)) {
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

