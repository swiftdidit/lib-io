#include <stdio.h>

#include "libio.h"

//*filename is another words for path, it just feels nicer.

//  -> Create a main path directory to keep organized! = char*
// CreateMainPath("C:\\Users\\fleek\\CProjects\\lib-io\\", "sixtynine.txt");

// example FILE *file =
// CreateFile("C:\\Users\\fleek\\CProjects\\lib-io\\sixtynine.txt", false);

// -> Create a new file = FILE* CreateFile(const char *filename, bool
// overwrite);

// example MyFile *myFile =
// CreateMyFile("C:\\Users\\fleek\\CProjects\\lib-io\\sixtynine.txt", false);

// -> Create a new 'MyFile' struct which contains FILE and FinalPath = MyFile*
// CreateMyFile(const char *filename, bool overwrite);

// -> Write all content to a file = void WriteAll(const char *content[], const
// char *path);

// -> Write a single line of content to a file = void WriteLine(int line, const
// char *content, const char *path);

// -> Append content to end of file = void AppendLine(const char *content, const
// char *path);

// -> Read a value from specified 'key' in text file = char* ReadValue(const
// char *path, const char *key);

// -> Read a single line of content specified in file = char* ReadLine(const
// char *path, int line);

// -> Read all content from file = char* ReadAll(const char *path);

int main() {
  char *path =
      CreatePath("C:\\Users\\fleek\\CProjects\\lib-io\\", "test.txt");
  printf("Value from key 'test': %s\n", ReadValue(path, "test"));

  // printf("Main path: %s\n\n",
  // CreateMainPath("C:\\Users\\fleek\\CProjects\\lib-io\\", "sixtynine.txt"));

  MyFile *myFile = CreateMyFile("", true);

  printf("\nMyFile Final Path: %s\n", myFile->finalPath);

  if (myFile->file) {
    printf("Success created a file!!!\n");

    WriteAll("Hello world\n     This is 69!", myFile->finalPath);
    AppendLine("\nTesting appended line", myFile->finalPath);
  }

  // printf("\nRead a line from %s\n->%s", myFile->finalPath,
  //        ReadLine(2, myFile->finalPath));

  // printf("\nReadALL TEST\n %s\n", ReadAll(myFile->finalPath));
  free(myFile);
  return 0;
}