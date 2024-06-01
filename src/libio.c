#include "libio.h"

char* CreatePath(const char* base, const char* filename) {
    size_t len = strlen(base) + strlen(filename) + 2;  // +1 for the separator, +1 for the null terminator
    char* path = malloc(len);
    if (path) {
        snprintf(path, len, "%s/%s", base, filename);
    }
    return path;
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
        "#CreateMyFile (FILE CREATION) Exception, the passed 'filename' is "
        "Empty "
        "and "
        "has a length of 0");
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

char* ReadValue(const char* path, const char* key) {
  FILE* file = fopen(path, "r");
  if (!FileExists(path)) {
    printf("'ReadValue from Key Exception': Error opening the file.\n");
    exit(1);
  }

  char line[256];
  char* value = NULL;
  while (fgets(line, sizeof(line), file)) {
    char* found = strstr(line, key);
    if (found) {
      found += strlen(key) + 1;  // Skip key and '='
      size_t len = strlen(found);
      if (found[len - 1] == '\n') found[len - 1] = '\0';  // Remove newline
      value = malloc(len + 1);
      if (value) strcpy(value, found);
      break;
    }
  }

  fclose(file);
  return value;
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

char* ReadAll(const char* path) {
  FILE* file = fopen(path, "rb");

  if (!FileExists(path)) {
    printf("'READALL Exception': Error opening the file.\n");
    exit(1);
  }

  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);

  char* content = (char*)malloc((length + 1) * sizeof(char));
  if (content == NULL) {
    printf("'READALL Exception': Memory allocation failed.\n");
    exit(1);
  }

  size_t readSize = fread(content, 1, length, file);
  if (readSize != length) {
    printf("'READALL Exception': Error reading the file.\n");
    free(content);
    exit(1);
  }

  content[length] = '\0';
  fclose(file);

  return content;
}

bool FileExists(const char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    return false;
  }

  return true;
}