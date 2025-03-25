#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int max = arr[0];
    for(int i = 0; i < n; i++) if (arr[i] > max) max = arr[i];
    
    double sum = 0;
    for(int i = 0; i < n; i++) sum += (double)arr[i] / max * 100;
    
    printf("%f", sum / n);
    return 0;
}