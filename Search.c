#include "Struct.c"
int SearchCategory(char CatergoryName[], Category **categories, int CategorySize )
{
    for(int i =0 ; i< CategorySize ; i++)
    {
        if (strcmp(CatergoryName, categories[i]->CategoryName)==0)
        {
            return i;
        }

    }
    return -1;
}
int SearchProduct( char productName[], Category **Categories, int indexCategory)
{
    for(int i =0 ; i< Categories[indexCategory]->Prodectcount ; i++)
    {
        if (strcmp(productName, Categories[indexCategory]->Product[i].ProductName)==0)
        {
            return i;
        }

    }
    return -1;
}
