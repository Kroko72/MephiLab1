#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "dynamicArray.h"


void printString(const void* toPrint)
{
    printf("%s\n", (const char*)toPrint);
}


void printChar(const void* toPrint)
{
    printf("%c\n", *(const char*)toPrint);
}


void printInt(const void* toPrint)
{
    printf("%d\n", *((int*)toPrint));
}


dynamic_array* extractWords(char str[])
{
    dynamic_array* words;
    arrayInit(&words, 16, GetStringFieldInfo());
    int i = 0;
    int start = 0;
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
            char* word = malloc(i - start + 1);
            strncpy(word, &str[start], i - start);
            word[i - start] = '\0';
            if(arrayAddItem(words, word, sizeof (word) + 1, GetStringFieldInfo()) == -1)
            {
                return NULL;
            }
            free(word);
        }
    }
    return words;
}


dynamic_array* findWord(char str[], char keyword[])
{
    dynamic_array* indexes;
    arrayInit(&indexes, 16, GetIntFieldInfo());
    int i = 0;
    int start = 0;
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
            char* word = malloc(i - start + 1);
            if(!word)
            {
                printf("Memory allocation error\n");
                exit(-1);
            }
            strncpy(word, &str[start], i - start);
            word[i - start] = '\0';
            if(strcmp(word, keyword) == 0)
            {
                if(arrayAddItem(indexes, &start, sizeof (word) + 1, GetIntFieldInfo()) == -1)
                {
                    return NULL;
                }
            }
            free(word);
        }
    }
    return indexes;
}