#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 531441 // ^12

char line[MAX_LEN + 1];

void cantor(int start, int length)
{
    if (length == 1) return;

    int third = length / 3;

    for (int i = start + third; i < start + 2 * third; i++) line[i] = ' ';

    cantor(start, third);
    cantor(start + 2 * third, third);
}

int main(void)
{
    int N;
    
    while (scanf("%d", &N) != EOF)
    {
        int len = (int)pow(3, N);
        memset(line, '-', len);
        line[len] = '\0';

        cantor(0, len);
        printf("%s\n", line);
    }

    return 0;
}