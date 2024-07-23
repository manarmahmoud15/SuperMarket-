#include "Struct.c"
void buyProduct(Category **categories, int productIndex, int CategoryIndex, int *buyCount,Product productToBuy[] )
{
    int TotalPrice,Quantity;
    productToBuy[*buyCount] = categories[CategoryIndex]->Product[productIndex];
    printf ("Enter Quantity of Product that Want To buy\n");
    scanf("%d", &Quantity);
    if (Quantity < categories[CategoryIndex]->Product[productIndex].Quantity )
    {
        categories[CategoryIndex]->Product[productIndex].Quantity -= Quantity;
    }
    else
    {
        printf("there are only %d of this product , do you want that y/n?\n", categories[CategoryIndex]->Product[productIndex].Quantity);
        if (toupper(getche())=='Y')
        {
            categories[CategoryIndex]->Product[productIndex].Quantity = 0;
        }
    }
    strcpy (productToBuy[*buyCount].ProductName, categories[CategoryIndex]->Product[productIndex].ProductName);
    productToBuy[*buyCount].ProductPrice =categories[CategoryIndex]->Product[productIndex].ProductPrice;
    productToBuy[*buyCount].Quantity =Quantity;
    printf("do you want another product ? y/n \n");

}
