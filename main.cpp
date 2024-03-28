#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    struct hash_table table = {};
    int answers = 0, len = 0;
    char* buffer = 0;

    table_ctor(&table);

    scanf("%d", &answers);
    scanf("%d\n", &len);

    buffer = (char*)calloc(len + 1, sizeof(char));
    
    for (int i = 0; i < len; i++)
        scanf("%c", &buffer[i]);

    work_with_table(&table, buffer, fill);

    scanf("%d\n", &len);
    free(buffer);

    buffer = (char*)calloc(len + 1, sizeof(char));
    
    for (int i = 0; i < len; i++)
        scanf("%c", &buffer[i]);

    work_with_table(&table, buffer, find);

    free(buffer);
}