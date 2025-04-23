#include <stdio.h>
#include <string.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++)
    {
        char vps[51];
        scanf("%s", vps);
        int is_vps = 0;
        int length = strlen(vps);

        for(int j = 0; j < length; j++)
        {
            if (vps[j] == '(') is_vps++;
            else is_vps--;

            if (is_vps < 0) break;
        }

        if(is_vps == 0) printf("%s\n", "YES");
        else printf("%s\n", "NO");
    }
    return 0;
}