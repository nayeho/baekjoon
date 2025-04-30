#include <stdio.h>

#define MAX 1000

int main(void)
{
    int N;
    int queue[MAX];
    int stack[MAX];
    int top = -1;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &queue[i]);

    int snack = 1;
    int index = 0;

    while (index < N)
    {
        // 순서대로 앞에서부터 확인
        // 만약, 큐에서 꺼냈는데 현재 받아야 되는 순서와 같으면
        // 인덱스와 순서(snack) 1 증가
        if (queue[index] == snack)
        {
            index++;
            snack++;
        }
        // 스택에 사람이 있다면 (top >= 0)
        // 그리고 스택의 가장 윗 부분에 
        // 현재 받아야 할 간식 번호와 일치한다면
        // 스택 숫자 줄이고 (top--)
        // 간식 순서 증가
        else if (top >= 0 && stack[top] == snack)
        {
            top--;
            snack++;
        }
        // 여기까지 도달했다면
        // 큐의 학생 순서도 아니고
        // 스택의 가장 윗 부분의 학생 순서도 아니므로
        // 그 학생을 스택에 넣자
        else stack[++top] = queue[index++];
    }

    // 큐가 마무리 된 후
    // 스택에 남아 있는 학생들을 차례로 꺼내서
    // 간식 순서랑 매칭 후
    // 매칭되면 쭉쭉 빼는 로직
    while (top >= 0 && stack[top] == snack)
    {
        top--;
        snack++;
    }

    // 결론적으로 모든 학생이 받았다면
    // snack이 N + 1에 도달하게 된다
    if (snack == N + 1) printf("Nice\n");
    else printf("Sad\n");

    return 0;
}