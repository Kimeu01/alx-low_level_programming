#include <stdio.h>

/**
 * main - prints all single digit numbers starting from 0 to 10
 * New line follows
 *  use putchar
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 48; n < 58; n++)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
