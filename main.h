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
//END

// FILE FUNCTIONS
void createFile(string fileName);
int countRows(string fileName);
//END

// STRING FUNCTIONS
string getDynString();
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
//END

//PRINT FUNCTIONS
void printCover();
void printPrimaryMenu();
void printCategoriesMenu();
void printProductsMenu();
//END

#endif // !MAIN_GUARDS