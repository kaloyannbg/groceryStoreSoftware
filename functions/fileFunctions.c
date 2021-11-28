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

void createFile(string fileName)
{
    if (!isFileExist(fileName))
    {
        fp = fopen(fileName, F_WRITE);
        fclose(fp);
        return;
    }
}

int countRows(string fileName) {
    createFile(fileName);
    char buffer[BUFFER_LENGTH] = {0};
    fp = fopen(fileName, F_READ);
    string fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    int countRow = 0;
    while(fileGets != NULL) {
        ++countRow;
        fileGets = fgets(buffer, BUFFER_LENGTH, fp);
    }
    fclose(fp);
    return countRow;
}