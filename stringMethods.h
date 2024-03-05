#ifndef stringMethods_H
#define stringMethods_H
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dynamicArray.h"


dynamic_array* extractWords(char str[]);
dynamic_array* findWord(char str[], char keyword[]);
void printChar(const void* toPrint);  // для внутренней работы
void printString(const void* toPrint);  // для внутренней работы
void printInt(const void* toPrint);  // для внутренней работы

#endif
