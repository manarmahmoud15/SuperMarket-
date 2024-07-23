#include "Struct.c"
void displayCategory (Category **category, int CategoryIndex)
{
    printf("category Name  \n");
    for (int i =0 ; i<CategoryIndex; i++)
    {
        printf("\t%s\n", category[i]->CategoryName );
    }
}
void displayProduct(Category **categories, int CategoryIndex)
{
    printf ("product Name  product Price  product Quantity\n");
    for (int i =0 ; i < categories[CategoryIndex]->Prodectcount; i++)
    {
        printf ("\t%s \t  %d\t\t %d\t\t \n",
                categories[CategoryIndex]->Product[i].ProductName ,
                categories[CategoryIndex]->Product[i].ProductPrice,
                categories[CategoryIndex]->Product[i].Quantity);
    }
}
