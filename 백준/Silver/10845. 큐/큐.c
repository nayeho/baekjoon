#include <stdio.h>
#include <string.h>

// 큐2를 먼저 풀어서 큐1에 덮어쓰기
#define MAX 10000

int queue[MAX];
int front_index = 0;
int back_index = 0;

void push(int x) { queue[back_index++] = x; }
void pop(void)
{
    if (front_index == back_index) printf("-1\n");
    else printf("%d\n", queue[front_index++]);
}
void size(void) { printf("%d\n", back_index - front_index); }
void empty(void) { printf("%d\n", front_index == back_index ? 1 : 0); }
void front(void)
{
    if (front_index == back_index) printf("-1\n");
    else printf("%d\n", queue[front_index]);
}
void back(void)
{
    if (front_index == back_index) printf("-1\n");
    else printf("%d\n", queue[back_index - 1]);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    char menu[10];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", menu);

        if (strcmp(menu, "push") == 0)
        {
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if (strcmp(menu, "pop") == 0) pop();
        else if (strcmp(menu, "size") == 0) size();
        else if (strcmp(menu, "empty") == 0) empty();
        else if (strcmp(menu, "front") == 0) front();
        else if (strcmp(menu, "back") == 0) back();
    }

    return 0;
}