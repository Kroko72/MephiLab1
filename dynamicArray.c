#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void arrayInit(dynamic_array** arrPtr, size_t capacity, FieldInfo* itemFieldInfo)
{
    dynamic_array *container;
    container = malloc(sizeof(**arrPtr));
    if(!container) {
        exit(-1);
    }
    container->size = 0;
    container->capacity = capacity;
    container->array = malloc(capacity * sizeof(void*));
    if (!container->array && (capacity))
    {
        exit(-1);
    }
    container->fieldInfo = *itemFieldInfo;
    *arrPtr = container;
}


void arrayFree(dynamic_array* container)
{
    for (int i = 0; i < container->size; i++) {
        free(container->array[i]);
    }
    free(container->array);
    container->size = 0;
    container->capacity = 0;
    free(container);
}


int arrayDeleteItem(dynamic_array* container, const int index)
{
    if (index >= container->size || index < 0) {
        return -1;
    }
    free(container->array[index]);
    for (int i = index; i < container->size - 1; i++)
    {
        container->array[i] = container->array[i + 1];
    }
    container->size--;
    return 0;
}


int arrayAddItem(dynamic_array* container, void* item, size_t itemSize, FieldInfo* itemFieldInfo)
{
    if(strcmp(container->fieldInfo.typeName, itemFieldInfo->typeName) != 0)
    {
        return -1;
    }
    if (container->size == container->capacity)
    {
        container->capacity *= 2;
        container->array = realloc(container->array, container->capacity * sizeof(void*));
        if (!container->array && container->capacity)
        {
            printf("Reallocation error\n");
            exit(-1);
        }
    }
    void* itemCopy = malloc(itemSize);
    if(!itemCopy && itemSize)
    {
        printf("Memory allocation error\n");
        exit(-1);
    }
    memcpy(itemCopy, item, itemSize);
    container->array[container->size] = itemCopy;
    container->size++;
    return 0;
}


int arrayUpdateItem(dynamic_array* container, int index, const void* item, size_t itemSize, FieldInfo* itemFieldInfo)
{
    if(strcmp(container->fieldInfo.typeName, itemFieldInfo->typeName) != 0)
    {
        return -2;
    }
    if (index >= container->size || index < 0)
    {
        return -1;
    }
    free(container->array[index]);
    void* itemCopy = malloc(itemSize);
    if(!itemCopy && itemSize)
    {
        printf("Memory allocation error\n");
        exit(-1);
    }
    memcpy(itemCopy, item, itemSize);
    container->array[index] = itemCopy;
    return 0;
}


void arrayPrint(const dynamic_array* container)
{
    for (size_t i = 0; i < (container->size); i++)
    {
        printf("%zu. ", i);
        container->fieldInfo.printElement(container->array[i]);
    }
}