#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 1001

struct Node
{
    char* data;

    struct Node* next;

    int qant;
};

struct hash_table
{
    struct Node* arr;
};

enum table_mode 
{
    fill = 1,
    find = 2
};

static unsigned long long * p_degrees = 0;

void table_ctor (struct hash_table* table);

unsigned long long pow (int x, int k);

void work_with_table (struct hash_table* table, char* buffer, enum table_mode mode);

void add_to_table (struct hash_table* table, const char* str);

unsigned long long get_hash (const char* str);

void node_dump (struct Node* node);

void node_ctor (struct Node* pos, const char* str);

int get_qant (struct hash_table* table, const char* str);

void table_dtor (struct hash_table* table);


#endif // HASH_TABLE_H