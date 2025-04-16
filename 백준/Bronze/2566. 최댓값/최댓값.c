#include <stdio.h>

int main(void)
{
	// 입력부
	int array[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	// 논리부 
	int max = -1;
	int max_row = 0;
	int max_col = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (array[i][j] > max)
			{
				max = array[i][j];
				max_row = i;
				max_col = j;
			}
		}
	}
	printf("%d\n%d %d\n", max, max_row + 1, max_col + 1);
	return 0;
}