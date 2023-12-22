#include "hash_tables.h"

/**
 * key_index - generates a distributed index according to a given hash
 *
 * @key: arg key passed
 * @size: arg size of the hash tables
 * Return: key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
