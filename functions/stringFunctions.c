#include "../main.h"

string getDynString()
{
    char buffer[BUFFER_LENGTH] = {0};
    scanf("%[^\n]s", buffer);
    string out = (string)malloc(strlen(buffer) + 1);
    strcpy(out, buffer);
    return out;
}

void saveDynStrInArr(string fileName, en_information enType)
{
    createFile(fileName);
    int totalRows = (countRows(fileName) + 1);
    if (enType == eCategory)
    {
        printf(" -- Enter category name: ");
        string str = getDynString();
        printf("Category %s was added sucesfully.", str);
        fp = fopen(fileName, F_WRITE_A);
        fprintf(fp, "%d,%s\n", totalRows, str);
        fclose(fp);
        return;
    }
    else if (enType == eProduct)
    {
        printf(" -- Choose category -- ");
        printNewLines(1);
        printCategoriesFromFile(FILE_CATEGORIES);
        printf(" -- Enter category id: ");
        int catId = getInt();
        if (catId < 1 || catId > countRows(FILE_CATEGORIES))
        {
            printf(" -- Sorry, but this category ID is invalid. -- ");
            return;
        }
        printf(" -- Enter product name: ");
        string str = getDynString();
        printf(" -- Enter product price: ");
        double price = getDouble();
        printf("Product %s with price: %.2f was added sucesfully.", str, price);
        fp = fopen(fileName, F_WRITE_A);
        fprintf(fp, "%d,%d,%s,%.2f\n", totalRows, catId, str, price);
        fclose(fp);
        return;
    }
}