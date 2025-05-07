#include <stdio.h>

#define MAX 5051 // 역순으로 밀림 (100 + 99 + 98 ... + 1) + 여유분 1개정도

typedef struct Document
{
    int index;
    int priority;
} Document;

// 가장 높은 중요도를 리턴하는 함수
int max_priority(Document queue[], int front, int back)
{
    int max = 0;
    for (int i = front; i < back; i++)
    {
        if (queue[i].priority > max)
            max = queue[i].priority;
    }
    return max;
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        Document queue[MAX];
        int front = 0;
        int back = 0;

        for (int j = 0; j < N; j++)
        {
            int priority;
            scanf("%d", &priority);
            queue[back].index = j;
            queue[back].priority = priority;
            back++;
        }

        int print_order = 0;

        while (front < back)
        {
            int max = max_priority(queue, front, back);
            Document current = queue[front++];

            if (current.priority < max) queue[back++] = current;
            else
            {
                print_order++;
                if (current.index == M)
                {
                    printf("%d\n", print_order);
                    break;
                }
            }
        }
    }
    return 0;
}