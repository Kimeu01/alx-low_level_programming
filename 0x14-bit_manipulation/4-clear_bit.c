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
	unsigned long int i;
	unsigned int hold;

	if (index > 64)
		return (-1);
	hold = index;
	for (i = 1; hold > 0; i *= 2, hold--)

		if ((*n >> index) & 1)
			*n -= i;

	return (1);
}
