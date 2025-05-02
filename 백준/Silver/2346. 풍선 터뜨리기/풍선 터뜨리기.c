/*
양방향 deque로 시간초과 발생했다
양방향 연결리스트로 접근하자

#include <stdio.h>

// 양방향 deque를 활용하자
#define MAX 2001

typedef struct
{
    int index;  // 풍선 번호
    int move;   // 이동할 칸 수
} Balloon;

Balloon deque[MAX];
int front_index = MAX / 2;
int back_index = MAX / 2;

void push_back(Balloon b) { deque[back_index++] = b; }
void push_front(Balloon b) { deque[--front_index] = b; }
Balloon pop_front(void) { return deque[front_index++]; }
Balloon pop_back(void) { return deque[--back_index]; }
int size(void) { return back_index - front_index; }

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        Balloon b = { i, x };
        push_back(b);
    }

    while (size() > 1)
    {
        Balloon current = pop_front();
        printf("%d ", current.index);

        int steps = current.move;

        if (steps > 0) for (int i = 0; i < steps - 1; i++) push_back(pop_front());
        else for (int i = 0; i < -steps; i++) push_front(pop_back());
    }
    
    Balloon current = pop_front();
    printf("%d\n", current.index);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int index;
    int move;
    struct Node* prev;
    struct Node* next;
} Node;

Node* create_node(int index, int move)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->move = move;
    node->prev = node->next = NULL;
    return node;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Node* head = NULL;
    Node* tail = NULL;

    // 양방향 연결 리스트 생성
    for (int i = 1; i <= N; i++)
    {
        int x;
        scanf("%d", &x);
        Node* new_node = create_node(i, x);

        if (!head)
        {
            head = tail = new_node;
            // 원형 연결
            head->prev = head->next = head;
        }
        else
        {
            new_node->prev = tail;
            new_node->next = head;
            tail->next = new_node;
            head->prev = new_node;
            tail = new_node;
        }
    }

    Node* current = head;
    for (int count = 0; count < N; count++)
    {
        printf("%d", current->index);
        if (count != N - 1) printf(" ");

        int move = current->move;

        // 현재 노드 제거
        current->prev->next = current->next;
        current->next->prev = current->prev;

        Node* temp = current;

        // 다음 노드 이동
        if (move > 0)
        {
            current = current->next;
            for (int i = 0; i < move - 1; i++) current = current->next;
        }
        else
        {
            current = current->prev;
            for (int i = 0; i < -move - 1; i++) current = current->prev;
        }

        free(temp);
    }

    printf("\n");
    return 0;
}