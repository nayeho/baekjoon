#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101];
    scanf("%s", s);
    
    int alphabet[26];

    for (int i = 0; i < 26; i++) alphabet[i] = -1;

    int size = 0;
    while (s[size] != '\0') size++;

    for (int i = 0; i < size; i++)
    {
        int index = (int)(s[i] - 'a');
        if (alphabet[index] == -1) alphabet[index] = i;
    }

    for (int i = 0; i < 26; i++) printf("%d ", alphabet[i]);

    return 0;
}