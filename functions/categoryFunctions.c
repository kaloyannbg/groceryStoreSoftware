#include "../main.h"

void putCategoriesInStructs(string fileName, int totalRows, t_categories *arrayOfStructs)
{
    int countLine = 0, comma = 0;
    fp = fopen(fileName, F_READ);

    char buffer[BUFFER_LENGTH] = {0};
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);

    while (fileGets != NULL)
    {
        arrayOfStructs[countLine].Category_Name = (string)malloc(strlen(buffer) + 1);
        string token = strtok(buffer, ",");
        while (token != NULL)
        {
            switch (comma)
            {
            case 0:
                arrayOfStructs[countLine].Category_Id = atoi(token);
                break;
            case 1:
                strcpy(arrayOfStructs[countLine].Category_Name, token);
                break;
            default:
                break;
            }
            token = strtok(NULL, ",");
            comma++;
        }

        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
        comma = 0;
        countLine++;
    }

    fclose(fp);
}

void printCategoriesFromStructs(string fileName, int totalRows, t_categories *arrayOfStructs)
{
    for (int i = 0; i < totalRows; i++)
    {
        printf("%d. %s", arrayOfStructs[i].Category_Id, arrayOfStructs[i].Category_Name);
    }
}

void printCategoriesChoice(int *secondMenuChoiceAdress, t_categories *arrayOfCategories)
{
    while (*secondMenuChoiceAdress != 0)
    {
        system("clear");
        printCover();
        printCategoriesMenu();
        printf("Please enter your choice: ");
        *secondMenuChoiceAdress = getInt();
        if (*secondMenuChoiceAdress == 1)
        {
            printCategoriesFromStructs(FILE_CATEGORIES, countRows(FILE_CATEGORIES), arrayOfCategories);
            doPause();
        }
        else if (*secondMenuChoiceAdress == 2)
        {
            saveDynStrInArr(FILE_CATEGORIES, eCategory);
            putCategoriesInStructs(FILE_CATEGORIES, countRows(FILE_CATEGORIES), arrayOfCategories);
            printNewLines(1);
            doPause();
        }
        else if (*secondMenuChoiceAdress == 0)
        {
            printf(" -- Primary menu -- ");
            return;
        }
    }
}

void printCategoriesFromFile(string fileName)
{
    char buffer[BUFFER_LENGTH] = {0};
    fp = fopen(fileName, F_READ);
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    while (fileGets != NULL)
    {
        printf("%s", buffer);
        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    }
    fclose(fp);
}

void printCategoryFromID(string fileName, int row)
{
    char buffer[BUFFER_LENGTH] = {0};
    int count = 0;
    fp = fopen(fileName, F_READ);
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    while (fileGets != NULL)
    {
        ++count;
        if (count == row)
        {
            string token = strtok(buffer, ",");
            int comma = 0;
            while (token != NULL)
            {
                if (comma == 1)
                {
                    char cutNewLineFromToken[BUFFER_LENGTH] = {0};
                    strcpy(cutNewLineFromToken, token);
                    cutNewLineFromToken[strlen(cutNewLineFromToken)-1] = '\0';
                    printf("%-10s", cutNewLineFromToken);
                    return;
                }
                comma++;
                token = strtok(NULL, ",");
            }
        }
        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    }
}