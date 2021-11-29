#ifndef MAIN_GUARDS
#define MAIN_GUARDS

#include "headers/includes.h"

extern FILE *fp;

// GLOBAL FUNCTIONS
void printNewLines(int count);
int getInt();
double getDouble();
void clean_stdin(void);
void doPause();
void cleanScreen();
string returnStringBillFileCounter(int iCounter);
void getCurrentTime(char *out);
void setColor();
//END

// FILE FUNCTIONS
void createFile(string fileName);
int countRows(string fileName);
int isFileEmpty(string fileName);
void printAllRowsFromFile(string fileName);
//END

// STRING FUNCTIONS
string getDynString();
void getDetailsForNewBill(t_categories *arrayOfCategories, t_products *arrayOfProducts);
//END

//CATEGORY FUNCTIONS
void saveDynStrInArr(string fileName, en_information enType);
void putCategoriesInStructs(string fileName, int totalRows, t_categories *arrayOfStructs);
void printCategoriesFromStructs(string fileName, int totalRows, t_categories *arrayOfStructs);
void printCategoriesChoice(int *secondMenuChoiceAdress, t_categories *arrayOfCategories);
void printCategoriesFromFile(string fileName);
void printCategoryFromID(string fileName, int row);
//END

//PRODUCT FUNCTIONS
void putProductsInStructs(string fileName, int totalRows, t_products *arrayOfStructs);
void printProductsFromStructs(string fileName, int totalRows, t_products *arrayOfStructs);
void printProductsChoice(int *secondMenuChoiceAdress, t_products *arrayOfProducts);
void printProductsByCatIdFromStruct(t_products *arrayOfProducts, int totalRows, int selectedCatId);
//END

//BILLS FUNCTIONS
void printBillChoice(int *secondMenuChoiceAdress, t_categories *arrayOfCategories, t_products *arrayOfProducts);
//END

//BILL FILE FUNCTIONS
int countBillFiles(string fileName);
//END

//PRINT FUNCTIONS
void printCover();
void printPrimaryMenu();
void printCategoriesMenu();
void printProductsMenu();
void printBillMenu();
//END

#endif // !MAIN_GUARDS