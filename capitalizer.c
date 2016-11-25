// C220 A4 Q
// Luke Paddock - 10157251

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
	
	fseek(file, 0, SEEK_END); //go to end of file
	filesize = ftell(file); //get the file size
	rewind(file);           //go backto beginning
	fcontents = malloc(filesize * (sizeof(char))); //create space for big string
	fread(fcontents, sizeof(char), filesize, file); //copy file to string
	fclose(file); //close file (we reopen it and replace its contents later)
	
	int i;
	int x = 0; //0 = dont capitalize this word
		   //1 = capitalize this word
	for (i = 1; i < strlen(fcontents); i++) //for ever char in string
	{	if (i==1) //manually capitalize first letter in string
		{ 
			fcontents[0] = toupper(fcontents[0]);
		}
		if (fcontents[i-1] == '\n') //if first of a line capitalize it
		{
			fcontents[i] = toupper(fcontents[i]);
			x = 0; 
		}	
		else if (fcontents[i-1] == ' ') //if char is start of word
		{
			if (x == 0) { x = 1; } //if we dont capitalize this word
			else if (x == 1)  //if we do
			{
				fcontents[i] = toupper(fcontents[i]);
				x = 0;
			}
		}
	}
	
	file = fopen(argv[1], "w+"); //open file wiping contents
	fprintf(file, "%s", fcontents); //print string to file
	fclose(file);
}
