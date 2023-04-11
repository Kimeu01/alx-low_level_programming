#include "main.h"

/**
 * get_endianness - check endianness
 *
 * Return: 0 if endian is big, or 1 if endian is little
 */
int get_endianness(void)
{
	int n = 1;
	char *c = (char *) &n;

	return (*c);
}

