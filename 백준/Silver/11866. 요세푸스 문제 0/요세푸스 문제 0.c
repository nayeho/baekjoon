#include <stdio.h>
#include <string.h>

#define MAX 1001 // 원형 Queue위해 공간 하나 추가

int queue[MAX];
int front_index = 0;
int back_index = 0;

void push(int x)
{
    // 선형으로 사용하니 런타임 에러(이유 : overflow)발생
    // 원형 Queue로 해결하자
    queue[back_index] = x;
    back_index = (back_index + 1) % MAX;
}
int pop(void)
{
    if (front_index == back_index) return -1;
    int value = queue[front_index];
    front_index = (front_index + 1) % MAX;
    return value;
}
int size(void) { return (back_index - front_index + MAX) % MAX; }

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) push(i);
    
    printf("<");
    while (size() > 1)
    {
        for(int i = 0; i < K - 1; i++) push(pop());
        printf("%d, ", pop());
    }
    printf("%d>\n", pop());
    
    return 0;
}