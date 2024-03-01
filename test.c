#include "test.h"


int testDynamicArray()
{
    int response = 0;
    dynamic_array* test_array;
    arrayInit(&test_array, 16, printChar);
    char test_value1 = 'p';  // ДОЛЖНА БЫТЬ ПРОВЕРКА НА СОВПАДЕНИЕ ТИПОВ
    arrayAddItem(test_array, &test_value1);
    arrayPrint(test_array);
    if (test_array->size != 1)
    {
        printf("arrayAddItem error");
        response = -1;
    }

    char test_value2 = 'q';
    arrayUpdateItem(test_array, 0, &test_value2);
    if (*(const char*)test_array->array[0] != test_value2)
    {
        printf("arrayUpdateValue error");
        response = -1;
    }
    arrayUpdateItem(test_array, -1, &test_value2);
    arrayDeleteItem(test_array, 0);
    if (test_array->size != 0)
    {
        printf("arrayDeleteItem error");
        response = -1;
    }
    arrayDeleteItem(test_array, -1);
    arrayFree(test_array);
    return response;
}


int testStringMethods()
{
    int response = 0;
    dynamic_array* test_extract_array1 = extractWords("Hello, world! How are you?");
    dynamic_array* test_extract_array2 = extractWords("");
    if ((test_extract_array1->size != 5) || (test_extract_array2->size != 0)){
        printf("extractWords error");
        response = -1;
    }
    dynamic_array* test_find_array1 = findWord("hello, world, hello", "hello");
    dynamic_array* test_find_array2 = findWord("", "world");
    dynamic_array* test_find_array3 = findWord("hello, world, hello", "");
    if ((*(int*)test_find_array1->array[0] != 0) || (*(int*)test_find_array1->array[1] != 14) || (test_find_array2->size != 0) || (test_find_array3->size != 0))
    {
        printf("findWord error");
        response = -1;
    }
    return response;
}
