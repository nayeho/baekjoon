#include <stdio.h>
#include <string.h>

// 문자열 최대길이 + 1(널문자) + 1(개행까지??)
// 101은 왜 실패하는건지에 대한 고민하기
#define MAX 102

// Stack을 구조체로 만들어서 전개해보자
typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack* s) { s->top = -1; }                       // 스택 초기화
int is_empty(Stack* s) { return s->top == -1; }            // 비어 있다면 1, 아니라면 0
void push(Stack* s, char ch) { s->data[++(s->top)] = ch; } // 스택에 새로운 값 추가
char pop(Stack* s) { return s->data[(s->top)--]; }         // 스택 가장 위에 있는 값 꺼내고 제거
char peek(Stack* s) { return s->data[s->top]; }            // 스택 가장 위에 있는 값 확인!

// 괄호가 잘 짝지어졌는지를 확인하는 함수
// 올바르게 짝 지어짐 -> 1 return
// 짝 짓기 실패 -> 0 return
int is_balanced(const char* str)
{
    Stack s;    // 구조체 선언
    init(&s);   // 스택 초기화 (현재 top은 -1)

    for (int i = 0; str[i]; i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '[') push(&s, ch); // 열리는 괄호를 스택에 push
        else if (ch == ')')
        {
            // 닫는 소괄호 등장 시 스택이 비어 있거나 스택 가장 윗쪽이 여는 소괄호가 아니라면 0 return
            // 아니라면 가장 위의 값 꺼내고 제거
            if (is_empty(&s) || peek(&s) != '(') return 0; 
            pop(&s);
        }
        else if (ch == ']') // 닫는 소괄호와 같은 로직
        {
            if (is_empty(&s) || peek(&s) != '[') return 0;
            pop(&s);
        }
    }
    
    // 모든 문자열 탐색 이후 괄호가 없으면 1 반환, 아니라면 0 반환
    return is_empty(&s);
}

int main(void) {
    char str[MAX];

    while (1) {
        fgets(str, MAX, stdin); // 공백까지 입력 받기, 표준 입력 스트림 사용
        // 개행까지 문자열 개수를 찾은 후 맨 마지막 엔터(개행)을 널 문자로 바꿔서 문자열임을 표시
        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, ".") == 0) break;

        printf("%s\n", is_balanced(str) ? "yes" : "no");
    }

    return 0;
}
