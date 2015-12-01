#ifndef READFILE_H
#define READFILE_H

struct FileBuffer{
	char *data;
	int size;
};

struct FileBuffer *readfile(char *filename);

#endif
