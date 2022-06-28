#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two string
 *
 * @s1: char pointer
 * @s2: char pointer
 *
 * Return: char pointer
 */


char *str_concat(char *s1, char *s2)
{
	int s1_len, s2_len, t_len, i = 0;
	char *ans;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	t_len = s1_len + s2_len;
	ans = malloc(sizeof(*ans) * t_len + 1);

	while (i < s1_len)
	{
		ans[i] = s1[i];
		i++;
	}

	while ((s2_len - 1) >= 0)
	{
		ans[i] = *s2;

		s2++;
		i++;
	}

	ans[i] = '\0';

	return (ans);

}
