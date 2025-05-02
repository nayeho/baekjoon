#include <stdio.h>
#include <string.h>

#define MAX 500001 // 원형 Queue위해 공간 하나 추가

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
    int N;
    scanf("%d", &N);
    // back_index = N; push를 호출하므로 back_index를 따로 설정하지 않아도 된다
    for (int i = 1; i <= N; i++) push(i);
    
    while (size() > 1)
    {
        pop();
        push(pop());
    }

    printf("%d\n", pop());
    return 0;
}