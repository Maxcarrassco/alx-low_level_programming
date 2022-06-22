#include "main.h"


/**
 * wildcmp - compare two strings
 *
 * @s1: char pointer
 * @s2: char pointer
 *
 * Return: int
 */


int wildcmp(char *s1, char *s2)
{
	if (!*s1)
		return (0);

	if (*s1 != *s2 && *s2 != '*' && !*s2)
		return (wildcmp(s1 + 1, s2));

	if (*s1 == '\0')
		return (1);

	return (wildcmp(s1 + 1, s2 + 1));
}