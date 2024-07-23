#include "Struct.c"
Category* ReSizeCategory(Category **categories, int *Size )
{
    *Size *=2;
    Category **NewCatogories= malloc(*Size *sizeof(Category));
    for (int i =0 ; i < *Size/2 ; i++)
    {
        NewCatogories[i] = categories[i];
    }
    free(categories);
    //category->Product[ProductCount] = malloc (size *sizeof(Product));
    return NewCatogories ;
}

/*Product* CreateProduct (size)
{
    Product *Product = malloc(size *sizeof(Product));
    return Product;
} */

Product* ReSizeProduct(Product *product, int *size)
{
    //  Category Category;
    *size *=2;
    Product *Newproduct= malloc(*size *sizeof(Product));
    for(int i =0 ; i< *size/2 ; i++)
    {
        Newproduct[i] = product[i];
    }
    free(product);
    return Newproduct ;
}
