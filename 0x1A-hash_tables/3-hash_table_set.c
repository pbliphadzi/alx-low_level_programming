 #include "hash_tables.h"

/**
 * hash_table_set - short description
 *
 * Description: long description
 *
 * @ht: hash table
 * @key: key
 * @value: value
 *
 * Return: return description
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index = 0;
    hash_node_t *new_node = NULL, *old_head = NULL;

    if (key == NULL || value == NULL || ht == NULL || strlen(key) == 0)
        return (-1); 

    new_node = (hash_node_t *)malloc(sizeof(hash_node_t));
    if (new_node == NULL)
        return (-1); 

    index = key_index((const unsigned char *)key, ht->size);
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = NULL;

    if ((ht->array)[index] == NULL)
    {
        (ht->array)[index] = new_node;
        return (1);
    }
    else
    {
        old_head = (ht->array)[index];
        while (old_head)
        {
            if (strcmp(old_head->key, key) == 0)
            {
                free(old_head->value);
                old_head->value = strdup(value);
                free(new_node->key);
                free(new_node->value);
                free(new_node);
                return (1);
            }
            old_head = old_head->next;
        }
        old_head = (ht->array)[index];
        new_node->next = old_head;
        (ht->array)[index] = new_node;
        return (1);
    }
}
