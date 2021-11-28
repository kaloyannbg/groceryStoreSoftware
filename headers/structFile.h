#include "../main.h"

typedef long long int llint;
typedef char *string;

struct S_Categories {
    int Category_Id;
    string Category_Name;
};

struct S_Products
{
    llint Product_Id;
    int Product_Category;
    string Product_Name;
    double Product_Price;
};

typedef struct S_Products t_products;
typedef struct S_Categories t_categories;