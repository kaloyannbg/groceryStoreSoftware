#include "../main.h"

void putProductsInStructs(string fileName, int totalRows, t_products *arrayOfStructs)
{
    int countLine = 0, comma = 0;
    fp = fopen(fileName, F_READ);

    char buffer[BUFFER_LENGTH] = {0};
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);

    while (fileGets != NULL)
    {
        arrayOfStructs[countLine].Product_Name = (string)malloc(strlen(buffer) + 1);
        string token = strtok(buffer, ",");
        while (token != NULL)
        {
            switch (comma)
            {
            case 0:
                arrayOfStructs[countLine].Product_Id = atoi(token);
                break;
            case 1:
                arrayOfStructs[countLine].Product_Category = atoi(token);
                break;
            case 2:
                strcpy(arrayOfStructs[countLine].Product_Name, token);
                break;
            case 3:
                arrayOfStructs[countLine].Product_Price = atof(token);
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

void printProductsFromStructs(string fileName, int totalRows, t_products *arrayOfStructs)
{
    // llint Product_Id;
    // int Product_Category;
    // string Product_Name;
    // double Product_Price;
    MAX_STARS;
    printNewLines(1);
    for (int i = 0; i < totalRows; i++)
    {
        printf("*** Category: ");
        printCategoryFromID(FILE_CATEGORIES, arrayOfStructs[i].Product_Category);
        printf("Product ID: %-4d ", arrayOfStructs[i].Product_Id);
        printf("%-31s", arrayOfStructs[i].Product_Name);
        printf("%-9.2f BGN ***", arrayOfStructs[i].Product_Price);
        printNewLines(1);
    }

    MAX_STARS;
    printNewLines(1);
}

void printProductsChoice(int *secondMenuChoiceAdress, t_products *arrayOfProducts)
{
    while (*secondMenuChoiceAdress != 0)
    {
        system("clear");
        printCover();
        printProductsMenu();
        printf("Please enter your choice: ");
        *secondMenuChoiceAdress = getInt();
        if (*secondMenuChoiceAdress == 1)
        {
            printProductsFromStructs(FILE_PRODUCTS, countRows(FILE_PRODUCTS), arrayOfProducts);
            doPause();
        }
        else if (*secondMenuChoiceAdress == 2)
        {
            saveDynStrInArr(FILE_PRODUCTS, eProduct);
            putProductsInStructs(FILE_PRODUCTS, countRows(FILE_PRODUCTS), arrayOfProducts);
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

void printProductsByCatIdFromStruct(t_products *arrayOfProducts, int totalRows, int selectedCatId)
{
    for (int i = 0; i < totalRows; i++)
    {
        if (arrayOfProducts[i].Product_Category == selectedCatId)
        {
            printf("*** PRODUCT ID: %-6d %-30s %-8.2f BGN ***", arrayOfProducts[i].Product_Id,
                   arrayOfProducts[i].Product_Name,
                   arrayOfProducts[i].Product_Price);
            printNewLines(1);
        }
    }
}