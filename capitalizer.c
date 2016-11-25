#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *fcontents;
	int filesize;
	char cchar; //current character
	FILE *file;
	file = fopen(argv[1], "r");
	
	fseek(file, 0, SEEK_END);
	filesize = ftell(file);
	rewind(file);
	fcontents = malloc(filesize * (sizeof(char)));
	fread(fcontents, sizeof(char), filesize, file);
	fclose(file);
	
	int i;
	int x = 0;
	for (i = 1; i < strlen(fcontents); i++)
	{
		if (fcontents[i-1] == '\n')
		{
			fcontents[i] = toupper(fcontents[i]);
			x = 0;
		}	
		else if (fcontents[i-1] == ' ')
		{
			if (x == 0) { x = 1; }
			else if (x == 1) 
			{
				fcontents[i] = toupper(fcontents[i]);
				x = 0;
			}
		}
	}
	
	file = fopen(argv[1], "w+");
	fprintf(file, "%s", fcontents);
	fclose(file);
}
