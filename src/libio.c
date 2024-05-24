#include "libio.h"

char* CreateMainPath(const char* path, const char* filename) {
  char finalPath[500];
  strcpy(finalPath, path);
  return strcat(finalPath, filename);
}

FILE* CreateFile(const char* filename, bool overwrite) {  // works
  if (!overwrite && FileExists(filename)) {
    printf(
        "#CreateFile 'overwrite = false' (FILE ALREADY EXISTS) Exception: %s\n",
        filename);
    return NULL;
  }

  size_t filenameLength = strlen(filename);
  if (filenameLength == 0) {
    printf(
        "#CreateFile (FILE CREATION) Exception, the passed 'filename' is Empty "
        "and "
        "has a length of 0: %s\n",
        filename);
    exit(EXIT_FAILURE);
    return NULL;
  }

  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("#CreateFile (FILE CREATION) Exception: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  fclose(file);
  return file;
}

MyFile* CreateMyFile(const char* filename, bool overwrite) {  // works
  MyFile* myFile = malloc(sizeof(MyFile));
  if (myFile == NULL) {
    printf("#CreateMyFile (Memory allocation issue) Exception: %s\n", filename);
    exit(1);
  }

  if (!overwrite && FileExists(filename)) {
    printf(
        "#CreateMyFile 'overwrite = false' (FILE ALREADY EXISTS) Exception: "
        "%s\n",
        filename);
    return NULL;
  }

  size_t filenameLength = strlen(filename);
  if (filenameLength == 0) {
    printf(
        "#CreateMyFile (FILE CREATION) Exception, the passed 'filename' is Empty "
        "and "
        "has a length of 0: %s\n",
        filename);
    exit(EXIT_FAILURE);
    return NULL;
  }

  FILE* file = fopen(filename, "w");
  if (file == NULL) {
    printf("#CreateMyFile (FILE CREATION) Exception: %s\n", filename);
    exit(EXIT_FAILURE);
  }
  fclose(file);

  myFile->file = file;
  myFile->finalPath = (char*)filename;

  return myFile;
}

void WriteAll(const char* content, const char* path) {  // works
  FILE* file = fopen(path, "w");
  if (file == NULL) return;

  fprintf(file, "%s", content);
  fclose(file);
}

void WriteLine(int line, const char* content, const char* path) {  // works well
  FILE* file = fopen(path, "r");
  char buffer[1000];
  int currentLine = 1;

  if (!FileExists(path)) {
    printf("'WRITELINE Exception': Error opening file.\n");
    exit(1);
  }

  fclose(file);
}

void AppendLine(const char* content, const char* path) {  // works
  FILE* file = fopen(path, "a");

  fprintf(file, "%s", content);
  fclose(file);
}

char* ReadLine(int line, const char* path) {  // works
  FILE* file = fopen(path, "r");

  if (!FileExists(path)) {
    printf("'READLINE Exception': Error opening the file.\n");
    exit(1);
  }

  char buffer[1000];
  int currentLine = 0;

  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    currentLine++;

    if (currentLine == line) {
      char* lineContent = (char*)malloc(strlen(buffer) + 1);

      if (lineContent == NULL) {
        printf("'READLINE Exception': Memory allocation failed.\n");
        exit(1);
      }

      strcpy(lineContent, buffer);
      fclose(file);
      return lineContent;
    }
  }

  fclose(file);
  return NULL;
}

char* ReadAll(const char* path) {  // todo: FIXME (will break, and is not
                                   // recommended for production use cases yet)
  FILE* file = fopen(path, "r");

  if (!FileExists(path)) {
    printf("'READALL Exception': Error opening the file.\n");
    exit(1);
  }

  char* content = 0;
  long length;

  if (file) {
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    content = (char*)malloc((length + 1) * sizeof(char));

    if (content) {
      fread(content, sizeof(char), length, file);
    }

    fclose(file);
  }

  content[length] = '\0';
  return content;
}

bool FileExists(const char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    return false;
  }

  return true;
}