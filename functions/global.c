#include "../main.h"

void clean_stdin()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int getInt()
{
    char buffer[BUFFER_LENGTH] = {0};
    scanf("%s", buffer);
    fflush(stdin);
    return atoi(buffer);
}

double getDouble()
{
    double lf = 0;
    scanf("%lf", &lf);
    return lf;
}

void printNewLines(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\n");
    }
}

void doPause()
{
    system("pause");
}

void cleanScreen()
{
    system("clear");
}

string returnStringBillFileCounter(int iCounter)
{
    char *pToString = calloc(MAX_FILE_BILL_LENGTH, sizeof(char));
    sprintf(pToString, "%d", iCounter);
    return pToString;
}

void getCurrentTime(char *out) // save current time in 'out' array
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    memset(out, '\0', 128);

    sprintf(out, "%02d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void setColor() {
    system("color 70");
}