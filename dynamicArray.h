#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stddef.h>
#include "fieldInfo.h"

typedef void (*PrintArrayElement)(const void* element);

typedef struct {
    size_t size;  // Размер
    size_t capacity;  // Вместимость
    void** array;  // Элементы
    FieldInfo fieldInfo;
} dynamic_array;


void arrayInit(dynamic_array** arrPtr, size_t capacity, FieldInfo* itemFieldInfo);
void arrayFree(dynamic_array* container);
int arrayAddItem(dynamic_array* container, void* item, size_t itemSize, FieldInfo* itemFieldInfo);
int arrayUpdateItem(dynamic_array* container, int index, const void* item, size_t itemSize, FieldInfo* itemFieldInfo);
int arrayDeleteItem(dynamic_array* container, int index);
void arrayPrint(const dynamic_array* container);

#endif