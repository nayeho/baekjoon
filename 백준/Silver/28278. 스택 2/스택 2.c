#include <stdio.h>

#define MAX 1000000

int stack[MAX]; // 동적할당 시 런타임 에러 발생하므로 정적으로 진행
int size = 0; // 배열의 크기를 전역에서 scope

void menu_1(void);
void menu_2(void);
void menu_3(void);
void menu_4(void);
void menu_5(void);

int main(void)
{
    int N;
    scanf("%d", &N);
    
    int menu;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &menu);
        switch(menu)
        {
        case 1: menu_1(); break;
        case 2: menu_2(); break;
        case 3: menu_3(); break;
        case 4: menu_4(); break;
        case 5: menu_5(); break;
        default: break;
        }
    }
    return 0;
}
void menu_1(void)
{
    // 1 X
    // 정수 X를 스택에 넣는다
    int X;
    scanf("%d", &X);
    stack[size++] = X;
}
void menu_2(void)
{
    // 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다.
    // 없다면 -1을 대신 출력한다.
    if (size == 0) printf("-1\n");
    else printf("%d\n", stack[--size]);
}
void menu_3(void)
{
    // 스택에 들어 있는 정수의 개수를 출력한다.
    printf("%d\n", size);
}
void menu_4(void)
{
    // 스택이 비어있으면 1, 아니면 0을 출력한다.
    printf("%d\n", size == 0 ? 1 : 0);
}
void menu_5(void)
{
    // 스택에 정수가 있다면 맨 위의 정수를 출력한다.
    // 없다면 -1을 대신 출력한다.
    if (size == 0) printf("-1\n");
    else printf("%d\n", stack[size - 1]);
}