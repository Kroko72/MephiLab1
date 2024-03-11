#include "test.h"
#include "fieldInfo.h"


// test dynamic array with chars
int firstTestDynamicArray()
{
    dynamic_array* test_array;
    arrayInit(&test_array, 16, GetCharFieldInfo());
    char test_value1 = 'p';
    if(arrayAddItem(test_array, &test_value1, sizeof (test_value1), GetCharFieldInfo()) == -1)
    {
        printf("0. arrayAddItem error\n");
        return -1;
    }
    if(*(char*)test_array->array[0] != test_value1)
    {
        printf("1. arrayAddItem error\n");
        return -1;
    }
    char test_value2[3] = "abc";
    if(arrayAddItem(test_array, &test_value2, sizeof (test_value2), GetStringFieldInfo()) != -1)
    {
        printf("2. arrayAddItem error\n");
        return -1;
    }
    char test_value3 = 'q';
    if(arrayUpdateItem(test_array, 0, &test_value3, sizeof (test_value3), GetCharFieldInfo()) == -1)
    {
        printf("0. arrayUpdateItem error\n");
        return -1;
    }
    if (*(const char*)test_array->array[0] != test_value3)
    {
        printf("1. arrayUpdateItem error\n");
        return -1;
    }
    if(arrayUpdateItem(test_array, -1, &test_value3, sizeof (test_value3), GetCharFieldInfo()) != -1)
    {
        printf("2. arrayUpdateItem error\n");
        return -1;
    }
    char test_value4[3] = "qwe";
    if(arrayUpdateItem(test_array, 0, &test_value4, sizeof (test_value4), GetStringFieldInfo()) != -2)
    {
        printf("3. arrayUpdateItem error\n");
        return -1;
    }
    if(arrayDeleteItem(test_array, 0) == -1)
    {
        printf("0. arrayDeleteItem error\n");
        return -1;
    }
    if (test_array->size != 0)
    {
        printf("1. arrayDeleteItem error\n");
        return -1;
    }
    if(arrayDeleteItem(test_array, -1) != -1)
    {
        printf("2. arrayDeleteItem error\n");
        return -1;
    }
    arrayFree(test_array);
    return 0;
}


// test dynamic array with strings
int secondTestDynamicArray()
{
    dynamic_array* test_array;
    arrayInit(&test_array, 16, GetStringFieldInfo());
    char test_value1[13] = "qweqweqweqwe";
    if(arrayAddItem(test_array, &test_value1, sizeof (test_value1), GetStringFieldInfo()) == -1)
    {
        printf("0. arrayAddItem error\n");
        return -1;
    }
    if(strcmp((char*)test_array->array[0], test_value1) != 0)
    {
        printf("1. arrayAddItem error\n");
        return -1;
    }
    char test_value2 = 'a';
    if(arrayAddItem(test_array, &test_value2, sizeof (test_value2), GetCharFieldInfo()) != -1)
    {
        printf("2. arrayAddItem error\n");
        return -1;
    }
    char test_value3[2] = "q";
    if(arrayUpdateItem(test_array, 0, &test_value3, sizeof (test_value3), GetStringFieldInfo()) == -1)
    {
        printf("0. arrayUpdateItem error\n");
        return -1;
    }
    if (strcmp((const char*)test_array->array[0], test_value3) != 0)
    {
        printf("1. arrayUpdateItem error\n");
        return -1;
    }
    if(arrayUpdateItem(test_array, -1, &test_value3, sizeof (test_value3), GetStringFieldInfo()) != -1)
    {
        printf("2. arrayUpdateItem error\n");
        return -1;
    }
    char test_value4[3] = "qwe";
    if(arrayUpdateItem(test_array, 0, &test_value4, sizeof (test_value4), GetCharFieldInfo()) != -2)
    {
        printf("3. arrayUpdateItem error\n");
        return -1;
    }
    if(arrayDeleteItem(test_array, 0) == -1)
    {
        printf("0. arrayDeleteItem error\n");
        return -1;
    }
    if (test_array->size != 0)
    {
        printf("1. arrayDeleteItem error\n");
        return -1;
    }
    if(arrayDeleteItem(test_array, -1) != -1)
    {
        printf("2. arrayDeleteItem error\n");
        return -1;
    }
    arrayFree(test_array);
    return 0;
}


int testStringMethods() {
    dynamic_array *test_extract_array1 = extractWords("Hello, world! How are you?");
    dynamic_array *test_extract_array2 = extractWords("");
    if (test_extract_array1->size != 5)
    {
        printf("0. extractWords error\n");
        return -1;
    }
    if (test_extract_array2->size != 0)
    {
        printf("1. extractWords error\n");
        return -1;
    }
    if (strcmp((char *) test_extract_array1->array[0], "Hello") != 0)
    {
        printf("2. extractWords error\n");
        return -1;
    }
    if (strcmp((char *) test_extract_array1->array[1], "world") != 0)
    {
        printf("3. extractWords error\n");
        return -1;
    }
    if (strcmp((char *) test_extract_array1->array[2], "How") != 0)
    {
        printf("4. extractWords error\n");
        return -1;
    }
    if (strcmp((char *) test_extract_array1->array[3], "are") != 0)
    {
        printf("5. extractWords error\n");
        return -1;
    }
    if (strcmp((char *) test_extract_array1->array[4], "you") != 0)
    {
        printf("6. extractWords error\n");
        return -1;
    }
    dynamic_array *test_find_array1 = findWord("hello, world, hello", "hello");
    dynamic_array *test_find_array2 = findWord("", "world");
    dynamic_array *test_find_array3 = findWord("hello, world, hello", "");
    if (*(int *) test_find_array1->array[0] != 0)
    {
        printf("0. findWord error\n");
        return -1;
    }
    if (*(int *) test_find_array1->array[1] != 14)
    {
        printf("1. findWord error\n");
        return -1;
    }
    if (test_find_array2->size != 0)
    {
        printf("2. findWord error\n");
        return -1;
    }
    if (test_find_array3->size != 0)
    {
        printf("3. findWord error\n");
        return -1;
    }
    return 0;
}
