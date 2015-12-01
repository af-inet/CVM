#include <stdlib.h>
#include <stdio.h>

#include "readfile.h"

char *readfile(char *filename){
	char * buffer = 0;
	long length;
	FILE * f = fopen (filename, "r");
	if(f==NULL) return NULL;

	int result = 0;

	if( f )
	{
		result = fseek(f, 0, SEEK_END);
		if(result==-1) return NULL;

		length = ftell(f);
		if(length==-1) return NULL;

		result = fseek(f, 0, SEEK_SET);
		if(result==-1) return NULL;
		
		buffer = malloc(length);
		if (buffer)
		{
			fread (buffer, 1, length, f);
		}
		fclose (f);
	}

	if(buffer)
		return buffer;
	else
		return NULL;
}
