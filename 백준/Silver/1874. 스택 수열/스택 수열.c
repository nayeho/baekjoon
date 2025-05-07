#include <stdio.h>

#define MAX 100000

int stack[MAX];
int top = -1;
int array[MAX];

char result[MAX * 2];
int index = 0;

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    int num = 1;
    for (int i = 0; i < n; i++)
    {
        int target = array[i];

        while (num <= target)
        {
            stack[++top] = num++;
            result[index++] = '+';
        }

        if (stack[top] == target)
        {
            top--;
            result[index++] = '-';
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < index; i++) printf("%c\n", result[i]);

    return 0;
}