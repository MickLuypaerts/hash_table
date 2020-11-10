#include "hash_table.h"

static unsigned int hash(char* value, int* hash_table_size)
{
    unsigned int index = 0;
    unsigned int value_lenght = strlen(value);

    for(int i = 0; i < value_lenght; i++)
    {
        index += value[i];
    }
    return index % *hash_table_size;
}

hash_table_t* create_hash_table(int size)
{
    hash_table_t* hash_table = malloc(sizeof(hash_table_t));
    hash_table->size = malloc(sizeof(int));
    *hash_table->size = size;
    hash_table->table = calloc(*hash_table->size, sizeof(struct bucket_t));
    return hash_table;
}

void print_hash_table(hash_table_t* hash_table)
{
    if(hash_table != NULL)
    {
        for(int i = 0; i < *hash_table->size; i++)
        {
            if(hash_table->table[i] != NULL)
            {
                printf("\tIndex: %i\tValue: %s", i, hash_table->table[i]->value);
                bucket_t* tmp = hash_table->table[i]->next;
                while(tmp != NULL)
                {
                    printf("\tValue: %s", tmp->value);
                    tmp = tmp->next;
                }
                printf("\n");
            }
            else
            {
                printf("\tIndex: %i\tValue: NULL\n ", i);
            }
        }
    }
    else
    {
        printf("hash table == NULL\n");
    }
}


bool find_node_in_hash_table(hash_table_t* hash_table, char* value)
{
    unsigned int index = hash(value, hash_table->size);
    bucket_t* tmp = hash_table->table[index];
    while(tmp != NULL)
    {
        if(strcmp(tmp->value, value) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}


void add_to_hash_table(hash_table_t** hash_table, char* value)
{   
    unsigned int index = hash(value, (*hash_table)->size);
    bucket_t** head = &(*hash_table)->table[index];
    unsigned int valueLenght = strlen(value) + 1;
    bucket_t* new_node = malloc(sizeof(bucket_t));
    new_node->value = malloc(sizeof(char) * valueLenght);
    strcpy(new_node->value, value);
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    bucket_t* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}


void reset_hash_table(hash_table_t* hash_table)
{
    for(int i = 0; i < *hash_table->size; i++)
    {
        bucket_t* tmp;
        if(hash_table->table[i] != NULL)
        {
            tmp = hash_table->table[i];
            hash_table->table[i] = hash_table->table[i]->next;
            free(tmp->value);
            free(tmp);
        }
        hash_table->table[i] = NULL;
    }
}

void free_hash_table(hash_table_t** hash_table)
{
    reset_hash_table(*hash_table);
    free((*hash_table)->size);
    (*hash_table)->size = NULL;
    free((*hash_table)->table);
    (*hash_table)->table = NULL;
    free(*hash_table); 
    *hash_table = NULL;
}