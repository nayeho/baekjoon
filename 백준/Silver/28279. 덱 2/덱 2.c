#include <stdio.h>
#include <string.h>

// deque(double-ended queue)로 진행하자
// 양끝 + 1
#define MAX 2000001

int deque[MAX];
int front_index = MAX / 2; // 가운데서 출발
int back_index = MAX / 2;

void push_front(int x) { deque[--front_index] = x; }
void push_back(int x) { deque[back_index++] = x; }
int pop_front(void)
{
    if (front_index == back_index) return -1;
    return deque[front_index++];
}
int pop_back(void)
{
    if (front_index == back_index) return -1;
    return deque[--back_index];
}
int size(void) { return back_index - front_index; }
int empty(void) { return front_index == back_index ? 1 : 0; }
int front(void)
{
    if (empty()) return -1;
    return deque[front_index];
}
int back(void)
{
    if (empty()) return -1;
    return deque[back_index - 1];
}

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int menu, x;
        scanf("%d", &menu);

        switch (menu)
        {
        case 1: scanf("%d", &x); push_front(x); break;
        case 2: scanf("%d", &x); push_back(x); break;
        case 3: printf("%d\n", pop_front()); break;
        case 4: printf("%d\n", pop_back()); break;
        case 5: printf("%d\n", size()); break;
        case 6: printf("%d\n", empty()); break;
        case 7: printf("%d\n", front()); break;
        case 8: printf("%d\n", back()); break;
        default: break;
        }
    }

    return 0;
}