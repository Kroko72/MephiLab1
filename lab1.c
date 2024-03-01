#include "dynamicArray.h"
#include "stringMethods.h"
#include "test.h"


void printBaseMenu()
{
    printf("\n--- Menu ---\n");
    printf("Choose type to work with: type 1 for char and 2 for string\n");
    printf("Enter 'STOP' for finish.\n");
    printf("Choose action: ");
}


void printCharMenu()
{
    printf("\n--- Menu ---\n");
    printf("0. Create new char array\n");
    printf("1. Add item\n");
    printf("2. Update item by index\n");
    printf("3. Delete item by index\n");
    printf("4. Show array elements\n");
    printf("5. Go back\n");
}


void printStringMenu()
{
    printf("\n--- Menu ---\n");
    printf("0. Create new string array\n");
    printf("1. Add item\n");
    printf("2. Update item by index\n");
    printf("3. Delete item by index\n");
    printf("4. Show array elements\n");
    printf("5. Extract words from string\n");
    printf("6. Find indexes of word in string\n");
    printf("7. Go back\n");
}


int main()
{
    // модульное тестирование перед переходом в меню
    if ((testDynamicArray() == -1) || (testStringMethods() == -1))
    {
        return -1;
    }
    //---------------------------------
    printf("All tests completed successfully!\n");

    while (1)
    {
        char input[70];
        printBaseMenu();
        scanf("%69s", input);

        if (strcmp(input, "STOP") == 0)
        {
            break;
        }

        int break_flag = 0;
        int array_created = 0;
        int work_type = atoi(input);
        switch (work_type)
        {
            case 1:
            {
                dynamic_array* char_array;
                while(1)
                {
                    printCharMenu();
                    scanf("%69s", input);
                    int action = atoi(input);
                    switch (action)
                    {
                        case 0:
                        {
                            if (array_created)
                            {
                                arrayFree(char_array);
                            }
                            arrayInit(&char_array, 16, printChar);
                            array_created = 1;
                            printf("Array created\n");
                            break;
                        }
                        case 1:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("write symbol to add\n");
                            scanf("%69s", input);
                            arrayAddItem(char_array, &input[0]);
                            printf("Item added\n");
                            break;
                        }
                        case 2:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("\nEnter new value: ");
                            scanf("%69s", input);
                            printf("\n");
                            arrayUpdateItem(char_array, index, &input[0]);
                            printf("Item updated\n");
                            break;
                        }
                        case 3:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("\n");
                            arrayDeleteItem(char_array, index);
                            printf("Item deleted\n");
                            break;
                        }
                        case 4:
                        {
                            if (!array_created){
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("\nElements of array: \n");
                            arrayPrint(char_array);
                            break;
                        }
                        case 5:
                        {
                            break_flag = 1;
                            if(array_created)
                            {
                                arrayFree(char_array);
                            }
                            break;
                        }
                        default:
                        {
                            printf("Unknown command\n");
                            break;
                        }
                    }
                    if(break_flag == 1)
                    {
                        break;
                    }
                }
                break;
            }
            
            case 2:
            {
                dynamic_array* string_array;
                while(1)
                {
                    printStringMenu();
                    scanf("%s", input);
                    int action = atoi(input);
                    switch (action)
                    {
                        case 0:
                        {
                            if (array_created)
                            {
                                arrayFree(string_array);
                            }
                            arrayInit(&string_array, 16, printString);
                            array_created = 1;
                            printf("Array created\n");
                            break;
                        }
                        case 1:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("Write string to add: ");
                            scanf(" %[^\n]", input);
                            printf("\n");
                            arrayAddItem(string_array, input);
                            printf("String added\n");
                            break;
                        }
                        case 2:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("\nEnter new value: ");
                            scanf(" %[^\n]", input);
                            printf("\n");
                            arrayUpdateItem(string_array, index, &input);
                            printf("Item updated\n");
                            break;
                        }
                        case 3:
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("\n");
                            arrayDeleteItem(string_array, index);
                            printf("Item deleted\n");
                            break;
                        }
                        case 4:
                        {
                            if (!array_created){
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("\nElements of array: \n");
                            arrayPrint(string_array);
                            break;
                        }
                        case 5:
                        {
                            printf("Enter string: ");
                            scanf(" %[^\n]", input);
                            printf("\n");
                            dynamic_array* words = extractWords(input);
                            if(words->size == 0){
                                printf("No words found\n");
                            }
                            else
                            {
                                printf("Founded words: \n");
                                arrayPrint(words);
                            }
                            arrayFree(words);
                            break;
                        }
                        case 6:
                        {
                            printf("Enter string: ");
                            scanf(" %[^\n]", input);
                            printf("\nEnter keyword: ");
                            char keyword[70];
                            scanf("%s", keyword);
                            printf("\n");
                            dynamic_array* indexes = findWord(input, keyword);
                            if(indexes->size == 0)
                            {
                                printf("No occurrences of the word were found\n");
                            }
                            else
                            {
                                printf("Keyword founded at indexes: \n");
                                arrayPrint(indexes);
                            }
                            arrayFree(indexes);
                            break;
                        }
                        case 7:
                        {
                            break_flag = 1;
                            if(array_created)
                            {
                                arrayFree(string_array);
                            }
                            break;
                        }
                        default:
                        {
                            printf("Unknown command\n");
                            break;
                        }
                    }
                    if(break_flag == 1)
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                printf("Unknown command\n");
                break;
            }
        }
    }
    return 0;
}
