#include "Struct.c"
void UpdateProduct(int indexProduct,Category **categories,int indexCategory)
{
  //  displayCategory(categories,indexCategory);
    Product ProductToUpdate ;
    printf("enter the ProductName to Update\n");
    scanf("%s", ProductToUpdate.ProductName);
    printf("enter the ProductPrice to Update\n");
    scanf("%d",&ProductToUpdate.ProductPrice);
    printf("enter the ProductQuantity to Update\n");
    scanf("%d",&ProductToUpdate.Quantity);
    categories[indexCategory]->Product[indexProduct] = ProductToUpdate ;
}
