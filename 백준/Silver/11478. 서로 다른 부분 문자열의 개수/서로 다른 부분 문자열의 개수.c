#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 200003
#define MAX_LEN 1001

typedef struct
{
    char *str;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

int hash(const char *str)
{
    // djb 2
    unsigned long h = 5381;
    // h * 33 + ch
    while (*str) h = ((h << 5) + h) + *str++;
    return h % HASH_SIZE;
}

// 삽입 성공하면 1, 실패하면 0 반환
int insert(const char *str)
{
    int h = hash(str);
    Node *curr = hash_table[h];
    while (curr)
    {
        if (strcmp(curr->str, str) == 0) return 0;
        curr = curr->next;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) exit(1);
    new_node->str = malloc(strlen(str) + 1);
    if (new_node->str == NULL) exit(1);
    strcpy(new_node->str, str);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;

    return 1;
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
            free(temp->str);
            free(temp);
        }
    }
}

int main(void)
{
    char S[MAX_LEN];
    scanf("%s", S);

    int len = strlen(S);
    int count = 0;
    char temp[MAX_LEN];

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            int sub_len = j - i + 1;
            strncpy(temp, S + i, sub_len);
            temp[sub_len] = '\0';
            count += insert(temp);
        }
    }

    printf("%d\n", count);

    free_table();
    return 0;
}
