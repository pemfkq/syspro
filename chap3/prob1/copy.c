#include <stdio.h>

// CHANGE CODE!!!!!

void copy(char from[], char to[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) !='\0')
		++i;
}
