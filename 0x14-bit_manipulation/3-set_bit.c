#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at an index
 * @n: decimal number passed by the pointer
 * @index: index position to change, starts from 0
 * Description: a bit is set at an index
 *
 * Return: 1, if error return -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int p = 1UL << index;

	if (index >= sizeof(unsigned long int) * 64)
	{
		return (-1);
	}


		*n |= p;

	return (1);
}
