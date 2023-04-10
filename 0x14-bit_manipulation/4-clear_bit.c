#include "main.h"
#include <stdio.h>
/**
 * clear_bit - sets value of bit to 0
 * @n: pointer to decimal number to change
 * @index: index position to change
 *
 * Return: 1 if it works, -1 if there is an error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 64)
	{
		return (-1);
	}
	*n &= ~(1UL << index);

	return (1);
}
