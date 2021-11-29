#include "../main.h"

int countBillFiles(string fileName)
{
    if (isFileEmpty(fileName))
    {
        fp = fopen(fileName, F_WRITE);
        int countStart = 0;
        fprintf(fp, "%d", countStart);
        fclose(fp);
        return 0;
    }

    if (!isFileEmpty(fileName))
    {
        int count = 0;
        fp = fopen(fileName, F_READ);
        fscanf(fp, "%d", &count);
        fclose(fp);
        return count;
    }
}