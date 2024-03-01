#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stddef.h>

typedef void (*PrintArrayElement)(const void* element);

typedef struct {
    size_t size;  // Размер
    size_t capacity;  // Вместимость
    void** array;  // Элементы
    PrintArrayElement printElement;  // Callback
} dynamic_array; 


void arrayInit(dynamic_array** arr_ptr, size_t capacity, PrintArrayElement printElement); 
void arrayFree(dynamic_array* container); 
void arrayAddItem(dynamic_array* container, void* item);
void arrayUpdateItem(dynamic_array* container, int index, const void* item);
void arrayDeleteItem(dynamic_array* container, int index);
void arrayPrint(const dynamic_array* container);

#endif