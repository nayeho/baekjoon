#include <stdio.h>

int main(void)
{
    char s[101];
    scanf("%s", s);

    int length = 0;
    while (s[length] != '\0') length++;

    printf("%d\n", length);

    return 0;
}