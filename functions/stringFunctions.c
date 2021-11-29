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

void getDetailsForNewBill(t_categories *arrayOfCategories, t_products *arrayOfProducts)
{
    char cont = 'y';
    int catChoice = 0, productChoice = 0, countTotalProducts = 0;
    double totalPrice = 0;
    int iFileCount = countBillFiles("BillFiles/countBillFiles.txt") + 1;
    char *fileCounterString = returnStringBillFileCounter(iFileCount);
    printf("FILE COUNT: %d FILE STRING COUNT %s\n", iFileCount, returnStringBillFileCounter(iFileCount));

    char currentBillFile[MAX_FILE_BILL_LENGTH] = {0};
    strcpy(currentBillFile, PATH_FILES_BILL);
    strcat(currentBillFile, fileCounterString);
    strcat(currentBillFile, ".txt");
    t_products *arrayOfBillDetails = (t_products *)calloc(MAX_BILL_PRODUCTS, sizeof(t_products));
    while (cont != 'n')
    {
        ++countTotalProducts;
        catChoice = 0, productChoice = 0;
        printNewLines(1);
        printCategoriesFromStructs(FILE_CATEGORIES, countRows(FILE_CATEGORIES), arrayOfCategories);
        printf(" -- Choose product category: ");
        catChoice = getInt();
        while (catChoice < 1 || catChoice > countRows(FILE_CATEGORIES))
        {
            printf(" -- Wrong CATEGORY ID -- ");
            printNewLines(1);
            printf(" -- Choose product category: ");
            catChoice = getInt();
        }

        printProductsByCatIdFromStruct(arrayOfProducts, countRows(FILE_PRODUCTS), catChoice);
        printf(" -- Choose product by ID: ");
        productChoice = getInt();
        productChoice -= 1;
        printf(" -- Your choice is %s with price %.2f -- ",
               arrayOfProducts[productChoice].Product_Name,
               arrayOfProducts[productChoice].Product_Price);
        printNewLines(1);
        arrayOfBillDetails[countTotalProducts - 1].Product_Category = arrayOfProducts[productChoice].Product_Category;
        arrayOfBillDetails[countTotalProducts - 1].Product_Id = arrayOfProducts[productChoice].Product_Id;
        arrayOfBillDetails[countTotalProducts - 1].Product_Name = (string)malloc(strlen(arrayOfProducts[productChoice].Product_Name) + 1);
        strcpy(arrayOfBillDetails[countTotalProducts - 1].Product_Name, arrayOfProducts[productChoice].Product_Name);
        arrayOfBillDetails[countTotalProducts - 1].Product_Price = arrayOfProducts[productChoice].Product_Price;

        printNewLines(1);
        printf(" -- Do you want to add more products? [y/n]: ");
        cont = getchar();
        if (cont == 'n')
        {
            fp = fopen("BillFiles/countBillFiles.txt", F_WRITE);
            fprintf(fp, "%d", iFileCount);
            fclose(fp);
            char stars[] = "********************************************************";
            fp = fopen(currentBillFile, F_WRITE_A);
            fprintf(fp, "%s\n", stars);
            char companyInfo[] = "***  Company: Grocery Store, Owner: Kaloyan Angelov  ***";
            fprintf(fp, "%s\n", companyInfo);
            fprintf(fp, "%s\n", stars);
            char time[128] = {0};
            getCurrentTime(time);
            fprintf(fp, "***      Receipt №: %d, Time: %s   ***\n", iFileCount, time);
            fprintf(fp, "%s\n", stars);

            for (int i = 0; i < countTotalProducts; i++)
            {
                fprintf(fp, "*** %-6d %-28s %-7.2f BGN  ***\n",
                        (i + 1),
                        arrayOfBillDetails[i].Product_Name,
                        arrayOfBillDetails[i].Product_Price);
                totalPrice += arrayOfBillDetails[i].Product_Price;
            }
            fprintf(fp, "%s\n", stars);
            fprintf(fp, "***              TOTAL PRICE: %-7.2f BGN             ***\n", totalPrice);

            fclose(fp);
            for (int i = 0; i < countTotalProducts; i++)
            {
                free(arrayOfBillDetails[i].Product_Name);
            }
            free(arrayOfBillDetails);
            printNewLines(1);
            system("clear");
            printCover();
            char PathF[MAX_BILL_PRODUCTS] = {0};
            strcpy(PathF, "BillFiles/");
            char sNum[MAX_BILL_PRODUCTS] = {0};
            itoa(iFileCount, sNum, 10);
            strcat(PathF, sNum);
            strcat(PathF, ".txt");
            printAllRowsFromFile(PathF);
        }
    }
}
