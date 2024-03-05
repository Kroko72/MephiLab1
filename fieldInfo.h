#ifndef UNTITLED_FIELDINFO_H
#define UNTITLED_FIELDINFO_H

#include <corecrt.h>
#include <stdlib.h>

typedef void (*PrintArrayElement)(const void* element);

typedef struct FieldInfo {
    const char* typeName;
    PrintArrayElement printElement;
} FieldInfo;

FieldInfo* GetCharFieldInfo();
FieldInfo* GetStringFieldInfo();
FieldInfo* GetIntFieldInfo();

#endif
