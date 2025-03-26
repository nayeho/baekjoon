#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[101];
    scanf("%s", s);
    
    int count = 0;
    for(int i = 0; s[i] != '\0';)
    {
        // dz= 확인 (3글자)
        if(s[i] == 'd' && s[i+1] == 'z' && s[i+2] == '=')
        {
            count++;
            i += 3;
        }
        // c=, c-, d-, lj, nj, s=, z= 확인 (2글자)
        else if((s[i] == 'c' && (s[i+1] == '=' || s[i+1] == '-')) ||
                (s[i] == 'd' && s[i+1] == '-') ||
                (s[i] == 'l' && s[i+1] == 'j') ||
                (s[i] == 'n' && s[i+1] == 'j') ||
                (s[i] == 's' && s[i+1] == '=') ||
                (s[i] == 'z' && s[i+1] == '='))
        {
            count++;
            i += 2;
        }
        else
        {
            count++;
            i++;
        }
    }

    printf("%d\n", count);
    return 0;
}