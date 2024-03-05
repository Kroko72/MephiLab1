#include "fieldInfo.h"
#include "stringMethods.h"
#include <stdlib.h>


static FieldInfo* CHAR_FIELD_INFO = NULL;
static FieldInfo* STRING_FIELD_INFO = NULL;
static FieldInfo* INT_FIELD_INFO = NULL;

FieldInfo* GetCharFieldInfo() {
    if (CHAR_FIELD_INFO == NULL) {
        CHAR_FIELD_INFO = malloc(sizeof(FieldInfo));
        CHAR_FIELD_INFO->typeName = "char";
        CHAR_FIELD_INFO->printElement = printChar;
    }
    return CHAR_FIELD_INFO;
}

FieldInfo* GetStringFieldInfo() {
    if (STRING_FIELD_INFO == NULL) {
        STRING_FIELD_INFO = malloc(sizeof(FieldInfo));
        STRING_FIELD_INFO->typeName = "string";
        STRING_FIELD_INFO->printElement = printString;
    }
    return STRING_FIELD_INFO;
}

FieldInfo* GetIntFieldInfo() {
    if (INT_FIELD_INFO == NULL) {
        INT_FIELD_INFO = malloc(sizeof(FieldInfo));
        INT_FIELD_INFO->typeName = "int";
        INT_FIELD_INFO->printElement = printInt;
    }
    return INT_FIELD_INFO;
}

