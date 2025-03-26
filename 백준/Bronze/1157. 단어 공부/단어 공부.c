#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000001];
    scanf("%s", s);
    int len = strlen(s);
    
    int alphabet[26] = {0};
    
    for(int i = 0; i < len; i++)
    {
        char ch = s[i];
        if(ch >= 'a' && ch <= 'z') ch -= 32;
        alphabet[ch - 'A']++;
    }
    
    int max_left = 0;
    int max_left_index = 0;
    int max_right = 0;
    int max_right_index = 25;
    
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] > max_left)
        {
            max_left = alphabet[i];
            max_left_index = i;
        }
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[25 - i] > max_right)
        {
            max_right = alphabet[25 - i];
            max_right_index = 25 - i;
        }
    }
    
    if(max_left_index == max_right_index) printf("%c", (char)(max_left_index + 'A'));
    else printf("?");
    return 0;
}