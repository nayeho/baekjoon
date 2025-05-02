#include <stdio.h>
#include <math.h>

#define OFFSET 4000
#define SIZE 8001

int count[SIZE] = { 0 };
int numbers[500000];
int total = 0;

int main(void)
{
    int N;
    scanf("%d", &N);

    int max = -4001;
    int min = 4001;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        numbers[i] = x;
        sum += x;

        if (x > max) max = x;
        if (x < min) min = x;

        count[x + OFFSET]++;
    }

    // 산술평균
    double avg = (double)sum / N;
    int rounded = (int)round(avg);
    printf("%d\n", rounded);

    // 중앙값 (카운팅 정렬 기반)
    int mid_count = 0;
    int median = 0;
    for (int i = 0; i < SIZE; i++)
    {
        mid_count += count[i];
        if (mid_count >= (N / 2) + 1)
        {
            median = i - OFFSET;
            break;
        }
    }
    printf("%d\n", median);

    // 최빈값
    int max_freq = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (count[i] > max_freq) max_freq = count[i];
    }

    int mode = 0;
    int mode_count = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (count[i] == max_freq)
        {
            mode = i - OFFSET;
            mode_count++;
            if (mode_count == 2) break;
        }
    }
    printf("%d\n", mode);

    // 범위
    printf("%d\n", max - min);

    return 0;
}