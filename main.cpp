#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    // clock_t start, end;
    // start = clock();

    struct hash_table table = {};
    int answers = 0, len = 0;
    char* buffer = 0;

    p_degrees = (unsigned long long *)calloc(30, sizeof(unsigned long long));

    table_ctor(&table);

    scanf("%d", &answers);
    scanf("%d\n", &len);

    buffer = (char*)calloc(len + 1, sizeof(char));
    
    for (int i = 0; i < len; i++)
        scanf("%c", &buffer[i]);

    // end = clock();
    // printf("\nSeconds: %f\n", float(end - start));

    work_with_table(&table, buffer, fill);

    // end = clock();
    // printf("\nSeconds: %f\n", float(end - start));

    scanf("%d\n", &len);
    free(buffer);

    buffer = (char*)calloc(len + 1, sizeof(char));
    
    for (int i = 0; i < len; i++)
        scanf("%c", &buffer[i]);

    work_with_table(&table, buffer, find);

    free(buffer);

    //table_dtor(&table);
    // end = clock();
    // printf("\nSeconds: %f\n", float(end - start));
}