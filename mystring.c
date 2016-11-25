// c220 A4 Q2
// Luke Paddock
// 10157251

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

char *safestrcat(char *a, char *b)
{
	int lengtha, lengthb;
	lengtha = strlen(a);
	lengthb = strlen(b);
	
	char *returnstring = malloc(lengtha + lengthb);

	int x;
	for (x = 0; x < lengtha; x++)
	{
		returnstring[x] = a[x];
	}
	
	int y;
	for (y = lengtha; y < (lengtha + lengthb); y++)
	{
		returnstring[y] = b[y-lengtha];
	}
	return returnstring;
}

int substring(char *source, int from, int n, char *target) 
{
	//return 0 on success, -1 on failure
	if ((from + n) > strlen(source)) { return -1; }
	if (from < 0)			 { return -1; }
	if (n < 1)			 { return -1; }
	int x, i;
	x = 0;
	for (i = from; i < (from + n); i++)
	{
		target[x] = source[i];
		x++;
	}
	return 0;
}
