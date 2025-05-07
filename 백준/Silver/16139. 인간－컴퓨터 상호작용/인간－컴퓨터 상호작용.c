#include <stdio.h>
#include <string.h>

#define MAX_LEN 200001

int sum[26][MAX_LEN];  // 각 알파벳별 누적 등장 횟수

int main(void)
{
    char string[MAX_LEN];
    int q;

    scanf("%s", string);
    int length = strlen(string);

    // 누적합 전처리
    for (int i = 0; i < length; i++)
    {
        int current_char = string[i] - 'a';

        for (int c = 0; c < 26; c++)
        {
            if (i == 0) sum[c][i] = (c == current_char) ? 1 : 0;
            else sum[c][i] = sum[c][i - 1] + ((c == current_char) ? 1 : 0);
        }
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        char target;
        int l, r;
        scanf(" %c %d %d", &target, &l, &r);

        int alpha_index = target - 'a';

        if (l == 0) printf("%d\n", sum[alpha_index][r]);
        else printf("%d\n", sum[alpha_index][r] - sum[alpha_index][l - 1]);
    }
    return 0;
}