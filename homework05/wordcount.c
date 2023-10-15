#include <stdio.h>

int main() {
  /*Read the file.*/

  char ch;
  int charCount = 0, wordCount = 0, lineCount = 0;
  int inw = 0;
  char filename[250];
  FILE *fp;

  printf("Enter a file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if(fp == NULL) {
    printf("Could not open the file %s\n", filename);
    return 1;
  }

  while ((ch = fgetc(fp)) != EOF) {
    charCount++;

    if(ch == ' ' || ch == '\t' || ch == '\0' || ch == '\n') {
      if (inw) {
        inw = 0;
        wordCount++;
      }

      if(ch == '\0' || ch == '\n') lineCount++;

    } else {
      inw = 1;
    }
  }

  printf("In the file %s:\n", filename);
  printf("Number of characters: %d.\n", charCount);
  printf("Number of words: %d.\n", wordCount);
  printf("Number of lines: %d.\n", lineCount);

  return wordCount;
}