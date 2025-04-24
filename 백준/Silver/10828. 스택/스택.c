#include <stdio.h>
#include <string.h>

#define MAX 10001 // 명령의 수 최대 : 10000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }
int is_empty(Stack* s) { return s->top == -1; }
void push(Stack* s, int num) { s->data[++(s->top)] = num; }
int pop(Stack* s) { return is_empty(s) ? -1 : s->data[(s->top)--]; }
int peek(Stack* s) { return is_empty(s) ? -1 : s->data[s->top]; }
int size(Stack* s) { return s->top + 1; }

int main(void) {
    
    int N;
    scanf("%d", &N);
    
    Stack s;    // 스택 선언
    init(&s);   // 스택 초기화

    for(int i = 0; i < N; i++)
    {
        char str[6]; // 입력 문자열 최대 : empty
        scanf("%s", str);
        
        if(strcmp(str, "push") == 0)
        {
            int num;
            scanf("%d", &num);
            push(&s, num);
        }
        else if(strcmp(str, "pop") == 0) printf("%d\n", pop(&s));
        else if(strcmp(str, "size") == 0) printf("%d\n", size(&s));
        else if(strcmp(str, "empty") == 0) printf("%d\n", is_empty(&s));
        else if(strcmp(str, "top") == 0) printf("%d\n", peek(&s));
    }

    return 0;
}
