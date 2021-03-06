#include "../main.h"

void printPrimaryMenu()
{
    MAX_STARS;
    printNewLines(1);
    printf("***                                      PRIMARY MENU                                 ***");
    printNewLines(1);
    printf("***                         1. Categories menu    2. Products menu                    ***");
    printNewLines(1);
    printf("***                         3. Bills menu         0. Exit                             ***");
    printNewLines(1);
    MAX_STARS;
    printNewLines(2);
}

void printCategoriesMenu()
{
    MAX_STARS;
    printNewLines(1);
    printf("***                                    Category option                                ***");
    printNewLines(1);
    printf("***                          1. Print categories  2. Add new category                 ***");
    printNewLines(1);
    MAX_STARS;
    printNewLines(2);
}

void printProductsMenu()
{
    MAX_STARS;
    printNewLines(1);
    printf("***                                    Products option                                ***");
    printNewLines(1);
    printf("***                          1. Print products  2. Add new product                    ***");
    printNewLines(1);
    MAX_STARS;
    printNewLines(2);
}

void printBillMenu()
{
    MAX_STARS;
    printNewLines(1);
    printf("***                                    Billing option                                 ***");
    printNewLines(1);
    printf("***                         1. Print bill by ID  2. Create new bill                   ***");
    printNewLines(1);
    MAX_STARS;
    printNewLines(2);
}