// c220 A4 Q2
// Luke Paddock
// 10157251

#include <stdlib.h>
#include <stdio.h>
#include "mystring.h"


int main() 
{
	//Test the safestrcat function
	char *string1 = "My name is, ";
	char *string2 = "Jon Smith";
	char *finalstring;
	finalstring = safestrcat(string1, string2);
	printf("safestrcat: %s\n", finalstring);
	free(finalstring);
	
	//Test the substring function
	char *bigstr = "The quick brown fox jumps over the lazy dog";
	char target[10];
	int result = substring(bigstr, 10, 20, target);
	if (result == 0) { printf("substring:  %s\n", target); }
	else { printf("There was an error : %d\n", result); }
	return result;
}
