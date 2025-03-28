#include <stdio.h>
#include <string.h> // strcat(문자열1, 문자열2) : 문자열 이어 붙이는 함수
#include <ctype.h> // atoi

int main(void)
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    
    char ch_A[6];
    char ch_B[5];
    char ch_C[5]; // 사실 뺄 때는 c까지 변환할 필요는 없지만 하는김에 해보자
    
    // sprintf(문자열 담을 곳, format형식 "%d" 등, 변환할 변수) : 출력 대신 문자열로 변환
    sprintf(ch_A, "%d", A);
    sprintf(ch_B, "%d", B);
    sprintf(ch_C, "%d", C);
    
    printf("%d\n", A + B - C);
    
    strcat(ch_A, ch_B); // ch_A 뒤에 ch_B를 붙인다 -> ch_A가 5자리 들어갈 수 있는지 확인
    
    printf("%d\n", atoi(ch_A) - atoi(ch_C)); // 마지막에도 개행하는 습관 들이자
    
    return 0;
}