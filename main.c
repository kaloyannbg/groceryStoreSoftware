#include "main.h"

int main(void)
{
    setColor();
    int menuChoice = 0, secondMenuChoice = 0;

    do
    {
        t_categories *arrayOfCategories = (t_categories *)calloc(countRows(FILE_CATEGORIES), sizeof(t_categories));
        putCategoriesInStructs(FILE_CATEGORIES, countRows(FILE_CATEGORIES), arrayOfCategories);

        t_products *arrayOfProducts = (t_products *)calloc(countRows(FILE_PRODUCTS), sizeof(t_products));
        putProductsInStructs(FILE_PRODUCTS, countRows(FILE_PRODUCTS), arrayOfProducts);

        system("clear");
        printCover();
        printPrimaryMenu();
        printf(" -- Please, enter menu choice: ");
        menuChoice = getInt();
        secondMenuChoice = 1;
        switch (menuChoice)
        {
        case 0:
            printf(" -- Bye, Bye -- ");
            break;
        case 1:
            printCategoriesChoice(&secondMenuChoice, arrayOfCategories);
            break;
        case 2:
            printProductsChoice(&secondMenuChoice, arrayOfProducts);
            break;
        case 3:
            printBillChoice(&secondMenuChoice, arrayOfCategories, arrayOfProducts);
        break;
        default:
            printf(" -- Invalid menu choice -- ");
            break;
        }
    } while (menuChoice != 0);

    return 0;
}
