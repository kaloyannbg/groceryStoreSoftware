#include "../main.h"

void newBill()
{
}

void printBillChoice(int *secondMenuChoiceAdress, t_categories *arrayOfCategories, t_products *arrayOfProducts)
{
    while (*secondMenuChoiceAdress != 0)
    {
        system("clear");
        printCover();
        printBillMenu();
        printf("Please enter your choice: ");
        *secondMenuChoiceAdress = getInt();
        if (*secondMenuChoiceAdress == 1)
        {
            printf(" -- Enter bill ID: ");
            int billID = getInt();
            char PathF[MAX_BILL_PRODUCTS] = {0};
            strcpy(PathF, "BillFiles/");
            char sNum[MAX_BILL_PRODUCTS] = {0};
            itoa(billID, sNum, 10);
            strcat(PathF, sNum);
            strcat(PathF, ".txt");
            printAllRowsFromFile(PathF);
            fclose(fp);
            printNewLines(1);
            doPause();
        }
        else if (*secondMenuChoiceAdress == 2)
        {
            getDetailsForNewBill(arrayOfCategories, arrayOfProducts);
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