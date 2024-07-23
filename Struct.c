#include <stdio.h>
#include <stdlib.h>
typedef struct Category Category ;
typedef struct Product Product ;
struct Product
{
    char ProductName[50];
    int ProductPrice ;
    int Quantity ;
};
struct Category
{
    //  int ProductCount = 10;
    int CategoryID ;
    char CategoryName[50];
    Product *Product;
    int Prodectcount;
    int maxProduct ;
};
