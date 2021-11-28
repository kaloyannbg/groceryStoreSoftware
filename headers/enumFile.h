#ifndef ENUM_GUARDS
#define ENUM_GUARDS

#include "../main.h"

enum eBool {
    false,
    true
};

enum eTypeOfInformation {
    eCategory = 1,
    eProduct
};

typedef enum eTypeOfInformation en_information;

#endif // !ENUM_GUARDS