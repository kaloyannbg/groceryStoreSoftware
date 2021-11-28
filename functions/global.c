#include "../main.h"

void clean_stdin()
{
    int c;
    do {
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

void printNewLines(int count) {
    for(int i = 0; i < count; i++)
    {
        printf("\n");
    }
}

void doPause() {
    system("pause");
}