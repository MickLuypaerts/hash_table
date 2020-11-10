#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Structure containing the value of the node and a pointer to the next node.
 */
typedef struct bucket_t
{
    char* value;
    struct bucket_t* next;
} bucket_t;


/**
 * @brief Structure containing the size of the hash table and the nodes.
 */
typedef struct hash_table_t
{
    int* size;
    bucket_t** table;
} hash_table_t;

/**
  * @brief  hashing function
  *
  * @param  value  value to be hashed
  * @param  hash_table_size  lenght of the hash table
  *
  * @return hash of the key used as index for the hash table
  */
static unsigned int hash(char* value, int* hash_table_size);

/**
 *  @brief    creates memory block for the hash table     
 *  @example  hash_table = create_hash_table(TABLE_SIZE);
 *  @param    size desired size for the hash_table
 *  
 *  @return   pointer to allocated memory table is initialized to NULL
 */
hash_table_t* create_hash_table(int size);

/**
 * @brief    printf all nodes in the table
 * 
 * @param    hash_table hash table to be printed
 */
void print_hash_table(hash_table_t* hash_table);

/**
 * @brief    checks if a value already exists in the table
 * 
 * @param    hash_table hash table to search
 * @param    value value to search for
 * 
 * @return   true if found false if not found
 */ 
bool find_node_in_hash_table(hash_table_t* hash_table, char* value);

/**
 * @brief    adds a node to the hash table
 * 
 * @param    hash_table memory address of the hash table
 * @param    value value to be added
 */
void add_to_hash_table(hash_table_t** hash_table, char* value);

/**
 * @brief    resets the hash table values to NULL
 * 
 * @param    hash_table hash table to be reset
 */ 
void reset_hash_table(hash_table_t* hash_table);


/**
 * @brief    frees the memory of the hash table
 * 
 * @param    hash_table memory location of the hash table
 */ 
void free_hash_table(hash_table_t** hash_table);

#endif
