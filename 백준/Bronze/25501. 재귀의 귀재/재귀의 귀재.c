#include <stdio.h>
#include <string.h>

int count;  // recursion 호출 횟수 세는 전역 변수

int recursion(const char *s, int l, int r)
{
    count++;  // 함수 호출될 때마다 count 증가
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s)
{
    count = 0;  // 호출 횟수 초기화
    return recursion(s, 0, strlen(s) - 1);
}

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char S[1001];  // 최대 길이 1000 + 널문자
        scanf("%s", S);

        int result = isPalindrome(S);
        printf("%d %d\n", result, count);
    }

    return 0;
}