#include <stdio.h>

// 정렬 2개로 풀어봤는데 메모리 초과
// 정적인 배열 (특히, merge sort는 통과하기 어렵다)

// 이 수는 10,000보다 작거나 같은 자연수이다
// 최댓값 + 1
#define MAX_NUM 10001  

// 1부터 10000까지의 수를 세는 배열
// 밀어내기
int counts[MAX_NUM];

int main(void)
{
    int N;
    scanf("%d", &N);

    int num;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        counts[num]++;
    }

    for (int i = 1; i < MAX_NUM; i++) {
        while (counts[i]--) {
            printf("%d\n", i);
        }
    }

    return 0;
}
