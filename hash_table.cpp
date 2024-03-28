#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

unsigned long long pow (int x, int k)
{
    unsigned long long  res = 1;
    if (k == 0)
        return 1;

    for (int i = 0; i < k; i++)
        res *= x;
    return res;
}

unsigned long long get_hash (const char* str)
{
    unsigned long long hash = 0;
    int p = 31;
    for (size_t i = 0; i < strlen(str); i++)
    {
        //printf("%c[%d]", str[i], str[i]);
        if (p_degrees[i] == 0)
            p_degrees[i] = pow(p, i);

        hash += (unsigned long long)(str[i] - 'a') * p_degrees[i];
    }   
    hash = hash % TABLE_SIZE;
    //printf("str - %s    hash - %u\n", str, hash);
    return (unsigned long long )hash;
}


void work_with_table (struct hash_table* table, char* buffer, enum table_mode mode)
{   
    int n = 0, ptr = 0;
    char* str = NULL;
    int ans = 0;

    size_t len = strlen(buffer);
    for (size_t i = 0; i < len; i++)
    {
        ptr = i;
        while (buffer[i] != ' ' && buffer[i] != '\0')
        {
            n++;
            i++;
        }
        str = (char*)calloc(n + 1, sizeof(char));
        strncpy(str, &buffer[ptr], n);
        n = 0;

        if (mode == fill)
            add_to_table(table, str);

        else if (mode == find)
        {
            ans = get_qant(table, str);
            printf("%d ", ans);
        }
        free(str);
    }
}

int get_qant (struct hash_table* table, const char* str)
{
    unsigned long long hash = get_hash(str);
    struct Node* pos = &table->arr[hash];

    if (pos->next == NULL)
        return 0;
    pos = pos->next;

    while (strcmp(pos->data, str) != 0)
    {
        if (pos->next != NULL)
            pos = pos->next;
        else
            return 0;
    }
    return pos->qant;
}

void add_to_table (struct hash_table* table, const char* str)
{
    unsigned long long hash = get_hash(str);
    struct Node* pos = &table->arr[hash];
    int new_node = 1;

    // if (pos->next == NULL)
    // {
    //     node_ctor(pos, str);
    //     pos->qant++;
    //     return;
    // }

    while (pos->next != NULL)
    {
        pos = pos->next;
        if (strcmp(pos->data, str) == 0)
        {
            new_node = 0;
            break;
        }
    }

    if (new_node)
    {
        pos->next = (struct Node*)calloc(1, sizeof(struct Node));
        pos = pos->next;
        node_ctor(pos, str);
    }
    pos->qant++;
    
    //node_dump(pos);
}

void node_ctor (struct Node* pos, const char* str)
{
    pos->data = (char*)calloc(strlen(str) + 1, sizeof(char));
    strncpy(pos->data, str, strlen(str));
}

void table_ctor (struct hash_table* table)
{
    table->arr = (struct Node*)calloc(TABLE_SIZE, sizeof(struct Node));
}

void table_dtor (struct hash_table* table) 
{
    struct Node* temp = NULL;
    struct Node* pos = NULL;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        pos = table->arr[i].next;
        while (pos->next != NULL)
        {
            temp = pos;
            pos = pos->next;
            free(temp);
        }
    }
    free(table->arr);
}


void node_dump (struct Node* node)
{
    printf("------------NODE_DUMP-----------\n");
    printf("adress - %p\n", node);
    //printf("hash - %u\n", node->hash);
    printf("data - %s\n", node->data);
    printf("next - %p\n", node->next);
    printf("qabt - %d\n", node->qant);
    printf("-------------DUMP_END-----------\n");
}