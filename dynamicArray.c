#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void arrayInit(dynamic_array** arr_ptr, size_t capacity, PrintArrayElement printElement)
{
    dynamic_array *container; 
    container = (dynamic_array*)malloc(sizeof(dynamic_array)); 
    if(!container) { 
        printf("Memory Allocation Failed\n"); 
        exit(0); 
    } 
    container->size = 0; 
    container->capacity = capacity; 
    container->array = (void **)malloc(capacity * sizeof(void*));
    if (!container->array) { 
        printf("Memory Allocation Failed\n"); 
        exit(0); 
    }
    container->printElement = printElement;
    *arr_ptr = container; 
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


void arrayDeleteItem(dynamic_array* container, const int index) 
{ 
    if (index >= container->size || index < 0) { 
        printf("Index Out of Bounds\n"); 
        return; 
    }
    free(container->array[index]); 
    for (int i = index; i < container->size - 1; i++) { 
        container->array[i] = container->array[i + 1]; 
    } 
    container->size--; 
} 


// ХУЕТА ПУШТО НЕТ ПРОВЕРКИ НА СООТВЕТСТВИЕ ТИПОВ
void arrayAddItem(dynamic_array* container, void* item)
{ 
    if (container->size == container->capacity)
    {
        void** temp = container->array; 
        container->capacity <<= 1; 
        container->array = (void **)realloc(container->array, container->capacity * sizeof(void*)); 
        if (!container->array)
        {
            printf("Out of Memory\n"); 
            container->array = temp; 
            return; 
        } 
    } 
    container->array[container->size] = strdup(item);
    container->size++; 
}


// ХУЕТА ПУШТО НЕТ ПРОВЕРКИ НА СООТВЕТСТВИЕ ТИПОВ
void arrayUpdateItem(dynamic_array* container, int index, const void* item) 
{ 
    if (index >= container->size || index < 0)
    {
        printf("Index Out of Bounds\n"); 
        return; 
    } 
    free(container->array[index]); 
    container->array[index] = strdup(item); 
} 


void arrayPrint(const dynamic_array* container)
{
    for (size_t i = 0; i < (container->size); i++)
    {
        printf("%zu. ", i);
        container->printElement(container->array[i]);
    }
}
