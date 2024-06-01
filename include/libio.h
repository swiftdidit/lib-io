#ifndef __LIBIO__
#define __LIBIO__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct MyFile {
    FILE *file;
    char *finalPath;
} MyFile;

char *CreatePath(const char *base, const char* filename);

//Create a File
FILE *CreateFile(const char *path, bool overwrite);

//Stores finalPath of file, and the FILE pointer
MyFile *CreateMyFile(const char *path, bool overwrite);

//Can overwrite a file with contents.
void WriteAll(const char *content, const char *path);

//Writes a line to the file..
void WriteLine(int line, const char *content, const char *path);
void AppendLine(const char *content, const char *path);

char *ReadValue(const char* path, const char *key);

//Return a single line from file
char *ReadLine(int line, const char *path);

//Read all lines from file
char *ReadAll(const char *path);

//Useful method to check file even exists!
bool FileExists(const char *path);

#endif //__LIBIO__