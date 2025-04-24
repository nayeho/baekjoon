#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 6
#define HASH_SIZE 20011  // 중간 테이블 해시 값 소수 선택
#define MAX_N 1000000

typedef struct
{
    char name[MAX_NAME_LEN];
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

char *result[MAX_N];  // 남아 있는 사람 이름 저장용
int result_count = 0; // 남아 있는 사람 수

int hash(const char *str)
{
    // djb2 해시 함수
    // start : 5381
    // hash * 33 + char
    unsigned long hash = 5381;
    while (*str) hash = ((hash << 5) + hash) + *str++;
    return hash % HASH_SIZE;
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

void delete(const char *str)
{
    int h = hash(str);
    Node *curr = hash_table[h];
    Node *prev = NULL;

    while (curr)
    {
        if (strcmp(curr->name, str) == 0)
        {
            if (prev) prev->next = curr->next;
            else hash_table[h] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void collect_remaining(void)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *curr = hash_table[i];
        while (curr)
        {
            result[result_count++] = curr->name;
            curr = curr->next;
        }
    }
}

int compare(const void *first, const void *second)
{
    // 사전 역순
    return strcmp(second, first);
}

// merge sort
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

void free_table(void)
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
    int n;
    char name[MAX_NAME_LEN];
    // "enter" 또는 "leave"
    char cmd[6];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", name, cmd);
        if (strcmp(cmd, "enter") == 0) insert(name);
        else delete(name);
    }

    collect_remaining();
    
    char **temp = malloc(sizeof(char *) * result_count);
    if (temp == NULL) return 1;

    merge_sort(result, temp, 0, result_count - 1);
    free(temp);

    for (int i = 0; i < result_count; i++) printf("%s\n", result[i]);

    free_table();
    return 0;
}
