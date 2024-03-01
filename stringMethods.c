#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "dynamicArray.h"


void printString(const void* to_print)
{
    printf("%s\n", (const char*)to_print);
}


void printChar(const void* to_print)
{
    printf("%c\n", *(const char*)to_print);
}


void printInt(const void* to_print)
{
    printf("%d\n", *((int*)to_print));
}


dynamic_array* extractWords(char str[])
{
    dynamic_array* words; 
    arrayInit(&words, 16, printString);
    int i = 0;
    int start = 0;
    int end = 0;
    size_t len = strlen(str);
    while (i < len) {
        while (i < len && !isalpha(str[i])) {
            i++;
        }
        if (isalpha(str[i])) {
            start = i;
            while (i < len && isalpha(str[i])) {
                i++;
            }
            end = i;
            char* word = (char*)malloc(end - start + 1);
            strncpy(word, &str[start], end - start);
            word[end - start] = '\0';
            arrayAddItem(words, word);
            free(word);
        }
    }
    return words;
}


dynamic_array* findWord(char str[], char keyword[])
{
    dynamic_array* indexes;
    arrayInit(&indexes, 16, printInt);
    int i = 0;
    int start = 0;
    int end = 0;
    size_t len = strlen(str);
    while (i < len) {
        while (i < len && !isalpha(str[i]))
        {
            i++;
        }
        if (isalpha(str[i]))
        {
            start = i;
            while (i < len && isalpha(str[i]))
            {
                i++;
            }
            end = i;
            char* word = (char*)malloc(end - start + 1);
            strncpy(word, &str[start], end - start);
            word[end - start] = '\0';
            if(strcmp(word, keyword) == 0)
            {
                arrayAddItem(indexes, &start);
            }
            free(word);
        }
    }
    return indexes;
}
