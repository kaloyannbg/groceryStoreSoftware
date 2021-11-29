#include "../main.h"

FILE *fp = NULL;

int isFileExist(string fileName)
{
    fp = fopen(fileName, F_READ);
    if (fp)
    {
        fclose(fp);
        return true;
    }
    fclose(fp);
    return false;
}

int isFileEmpty(string fileName)
{
    createFile(fileName);
    fp = fopen(fileName, F_READ);
    char buffer[MAX_BILL_PRODUCTS] = {0};
    string fileGets = fgets(buffer, MAX_BILL_PRODUCTS, fp);
    if (fileGets == NULL)
    {
        fclose(fp);
        return 1;
    }
    fclose(fp);
    return 0;
}

void createFile(string fileName)
{
    if (!isFileExist(fileName))
    {
        fp = fopen(fileName, F_WRITE);
        fclose(fp);
        return;
    }
}

int countRows(string fileName)
{
    createFile(fileName);
    char buffer[BUFFER_LENGTH] = {0};
    fp = fopen(fileName, F_READ);
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    int countRow = 0;
    while (fileGets != NULL)
    {
        ++countRow;
        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    }
    fclose(fp);
    return countRow;
}

void printAllRowsFromFile(string fileName) {
    char buffer[BUFFER_LENGTH] = {0};
    fp = fopen(fileName, F_READ);
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    while(fileGets != NULL) {
        printf("%s", buffer);
        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    }
    fclose(fp);
}