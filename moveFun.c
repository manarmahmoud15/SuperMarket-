#include "Struct.c"
void moveProduct( Category **categories,int indexOldCategory,int indexNewCategory, int ProductIndex)
{
    Product product = categories[indexOldCategory]->Product[ProductIndex];
    printf("----->Name : %s\n",product.ProductName);
    categories[indexNewCategory]->Product[categories[indexNewCategory]->Prodectcount] =product;
    categories[indexNewCategory]->Prodectcount+=1;
    delProduct(categories[indexOldCategory]->Product[ProductIndex].ProductName,categories,indexOldCategory);
}
