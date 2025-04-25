#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 21
#define MAX_N 500000
#define HASH_SIZE 2000003

typedef struct {
    char name[MAX_LEN];
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];
char *result[MAX_N];
int result_count = 0;

// djb 2
int hash(const char *str)
{
    unsigned long h = 5381;
    // h * 33 + char
    while (*str) h = ((h << 5) + h) + *str++;
    return h % HASH_SIZE;
}

void insert(const char *str)
{
    int h = hash(str);
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) exit(1);
    strcpy(new_node->name, str);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

int exists(const char *str)
{
    int h = hash(str);
    Node *curr = hash_table[h];
    while (curr)
    {
        if (strcmp(curr->name, str) == 0) return 1;
        curr = curr->next;
    }
    return 0;
}

int compare(const char *first, const char *second)
{
    return strcmp(first, second); // 오름차순
}

void merge(char **array, char **temp, int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (compare(array[i], array[j]) <= 0) temp[k++] = array[i++];
        else temp[k++] = array[j++];
    }

    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int i = left; i <= right; i++) array[i] = temp[i];
}

void merge_sort(char **array, char **temp, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, temp, left, mid);
        merge_sort(array, temp, mid + 1, right);
        merge(array, temp, left, mid, right);
    }
}

void free_table()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int main(void)
{
    int N, M;
    char name[MAX_LEN];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", name);
        insert(name);
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%s", name);
        if (exists(name))
        {
            result[result_count] = malloc(strlen(name) + 1);
            strcpy(result[result_count++], name);
        }
    }

    char **temp = malloc(sizeof(char *) * result_count);
    if (temp == NULL) return 1;

    merge_sort(result, temp, 0, result_count - 1);
    free(temp);

    printf("%d\n", result_count);
    for (int i = 0; i < result_count; i++) printf("%s\n", result[i]);

    free_table();
    for (int i = 0; i < result_count; i++) free(result[i]);

    return 0;
}