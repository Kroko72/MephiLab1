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
    printf("Choose action: ");
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
    printf("Choose action: ");
}


int main()
{
    // module (fuzz?) tests before main logic
    if ((firstTestDynamicArray() == -1) || (testStringMethods() == -1) || (secondTestDynamicArray() == -1))
    {
        return -1;
    }
    //---------------------------------
    printf("All tests completed successfully!\n");

    while (1)
    {
        char input[30] = {0};
        printBaseMenu();
        scanf("%s", input);

        if (strcmp(input, "STOP") == 0)
        {
            break;
        }

        int break_flag = 0;
        int array_created = 0;
        int work_type = atoi(input);  // 1 - for char, 2 - for string
        switch (work_type)
        {
            case 1:  // working with chars
            {
                dynamic_array* charArray;
                while(1)
                {
                    printCharMenu();
                    scanf("%s", input);
                    int action = atoi(input);  // look at printCharMenu to find out possible values
                    switch (action)
                    {
                        case 0:  // create (or recreate) array
                        {
                            if (array_created)
                            {
                                arrayFree(charArray);
                            }
                            arrayInit(&charArray, 16, GetCharFieldInfo());
                            array_created = 1;
                            printf("Array created\n");
                            break;
                        }
                        case 1:  // add item to array
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("write symbol to add: ");
                            scanf("%s", input);
                            if(arrayAddItem(charArray, &input[0], sizeof (input[0]), GetCharFieldInfo()) == -1)
                            {
                                printf("Item types does not match\n");
                            }
                            else
                            {
                                printf("Item added\n");
                            }
                            break;
                        }
                        case 2:  // update the value of an array element
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("Enter new value: ");
                            scanf("%s", input);
                            int response = arrayUpdateItem(charArray, index, &input[0], sizeof (input[0]), GetCharFieldInfo());
                            switch (response)
                            {
                                case -2:
                                {
                                    printf("Item types does not matching\n");
                                    break;
                                }
                                case -1:
                                {
                                    printf("Index out of bounds\n");
                                    break;
                                }
                                default:
                                {
                                    printf("Item updated\n");
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:  // delete an array element
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            if(arrayDeleteItem(charArray, index) == -1)
                            {
                                printf("Index out of bounds\n");
                            }
                            else
                            {
                                printf("Item deleted\n");
                            }
                            break;
                        }
                        case 4:  // print elements of array
                        {
                            if (!array_created){
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("\nElements of array: \n");
                            arrayPrint(charArray);
                            break;
                        }
                        case 5:  // go back to base menu
                        {
                            break_flag = 1;
                            if(array_created)
                            {
                                arrayFree(charArray);
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

            case 2:  // working with strings
            {
                dynamic_array* stringArray;
                while(1)
                {
                    printStringMenu();
                    scanf("%s", input);
                    int action = atoi(input);  // look at printStringMenu to find out possible values
                    switch(action)
                    {
                        case 0:  // create (or recreate) array
                        {
                            if(array_created)
                            {
                                arrayFree(stringArray);
                            }
                            arrayInit(&stringArray, 16, GetStringFieldInfo());
                            array_created = 1;
                            printf("Array created\n");
                            break;
                        }
                        case 1:  // add item to array
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("Write string to add: ");
                            scanf(" %[^\n]", input);
                            if(arrayAddItem(stringArray, (void*)&input, strlen(input) + 1, GetStringFieldInfo()) == -1)
                            {
                                printf("Item types does not match\n");
                            }
                            else
                            {
                                printf("String added\n");
                            }
                            break;
                        }
                        case 2:  // update the value of an array element
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            printf("Enter new string: ");
                            scanf(" %[^\n]", input);
                            int response = arrayUpdateItem(stringArray, index, &input, strlen (input) + 1, GetStringFieldInfo());
                            switch (response)
                            {
                                case -2:
                                {
                                    printf("Item types does not matching\n");
                                    break;
                                }
                                case -1:
                                {
                                    printf("Index out of bounds\n");
                                    break;
                                }
                                default:
                                {
                                    printf("Item updated\n");
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:  // delete an array element
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            int index;
                            printf("Enter index: ");
                            scanf("%d", &index);
                            if(arrayDeleteItem(stringArray, index) == -1)
                            {
                                printf("Index out of bounds\n");
                            }
                            else
                            {
                                printf("String deleted\n");
                            }
                            break;
                        }
                        case 4:  // print elements of array
                        {
                            if (!array_created)
                            {
                                printf("Array not created yet\n");
                                break;
                            }
                            printf("\nElements of array: \n");
                            arrayPrint(stringArray);
                            break;
                        }
                        case 5:  // extract words from string
                        {
                            printf("Enter string: ");
                            scanf(" %[^\n]", input);
                            dynamic_array* words = extractWords(input);
                            if(words == NULL)
                            {
                                printf("Array adding word error\n");
                                break;
                            }
                            if(words->size == 0)
                            {
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
                        case 6:  // find word indexes in a string
                        {
                            printf("Enter string: ");
                            scanf(" %[^\n]", input);
                            printf("Enter keyword: ");
                            char keyword[70];
                            scanf("%s", keyword);
                            printf("\n");
                            dynamic_array* indexes = findWord(input, keyword);
                            if(indexes == NULL)
                            {
                                printf("Find word function adding index error\n");
                                break;
                            }
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
                        case 7:  // go back to base menu
                        {
                            break_flag = 1;
                            if(array_created)
                            {
                                arrayFree(stringArray);
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