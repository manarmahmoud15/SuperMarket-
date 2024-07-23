#include "Struct.c"
void delCategory(Category **categories, int indexCategory,int *countCategory)
{
    for (int i=indexCategory ; i< *countCategory-1; i++)
    {
        categories[i] = categories[i+1];
    }
    *countCategory-=1;
}
void delProduct(char ProductName[],Category **categories, int indexCategory )
{
    for (int i= 0 ; i <categories[indexCategory]->Prodectcount ; i++)
    {
        if (strcmp(ProductName, categories[indexCategory]->Product[i].ProductName)==0)
        {
            for(int j = i ; j<categories[indexCategory]->Prodectcount-1 ; j++)
            {
                categories[indexCategory]->Product[j] = categories[indexCategory]->Product[j+1];
            }
            categories[indexCategory]->Prodectcount --;
        }
    }
}
