#include "Struct.c"
void CallAddProduct(Category **categories, int countCategory)
{
    char categoryName[50];

    displayCategory(categories,countCategory);
    printf("choose category that want to add product in \n");
    scanf("%s", categoryName);
    int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
    if(indexOfCategory != -1)
    {
        displayProduct(categories, indexOfCategory);
        printf("Do you Want To Add new Product ? Y/N\n");
        while (toupper(getche())=='Y')
        {
            AddProduct(categories,indexOfCategory,countCategory);
            printf("enter another Product ? Y/N\n");
        }

        printf("product is Added successfully ");
    }
    else
    {
        printf("not exist, please enter another category \n");
        displayCategory(categories,countCategory);
        printf("choose category that want to add product in \n");
        scanf("%s", categoryName);
        int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
        if(indexOfCategory != -1)
        {
            displayProduct(categories, indexOfCategory);
            printf("Do you Want To Add new Product ? Y/N\n");
            while (toupper(getche())=='Y')
            {
                AddProduct(categories);
                printf("enter another Product ? Y/N\n");
            }

            printf("product is Added successfully ");
        }
    }

}
void CallDeleteCategory(Category **categories, int *countCategory)
{
    displayCategory(categories,*countCategory);
    char categoryName[50];
    printf ("Enter Name Of Category that Want To Delete\n");
    scanf("%s", categoryName);
    int indexOfCategory = SearchCategory(categoryName, categories, *countCategory);
    if(indexOfCategory != -1)
    {
        delCategory(categories, indexOfCategory, countCategory);
        printf("this %s is deleted successfully ", categoryName);
    }
    else
    {
        printf("this Category Isn't Exist\n");
    }
}
void CallDeleteProduct( Category **categories, int countCategory )
{
    int indexOfCategory, indexOfProduct;
    char categoryName[50],ProductName[50] ;
    displayCategory(categories,countCategory);
    printf("Enter Name of Category that want to delete product from it\n");
    scanf("%s", categoryName);
    indexOfCategory = SearchCategory(categoryName, categories, countCategory);
    if(indexOfCategory != -1)
    {
        displayProduct(categories,indexOfCategory);
        printf ("Enter Name Of Product that Want To Delete\n");
        scanf ("%s", ProductName);
        int indexOfProduct = SearchProduct(ProductName, categories, indexOfCategory);
        if (indexOfProduct !=-1 )
        {
            printf("this product is deleted successfully");
            delProduct(ProductName,categories,indexOfCategory);
        }
        else
        {
            printf("this Product Isn't Exist\n");
        }
    }
    else
    {
        printf("this Category Isn't Exist\n");
    }
}
void CallDisplayProduct (Category **categories, int countCategory)
{
    char categoryName[50],ProductName[50] ;
    displayCategory(categories,countCategory);
    printf("Enter Name Of Category To Display Product\n");
    scanf("%s", categoryName);
    int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
    if(indexOfCategory != -1)
    {
        displayProduct(categories, indexOfCategory);
    }
    else
    {
        printf("Not Exist\n");
    }
    printf("do you display another Catedory's Product ? y/n \n");
    while (toupper(getche())=='Y')
    {
        printf("Enter Name Of Category To Display Product\n");
        scanf("%s", categoryName);
        int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
        if(indexOfCategory != -1)
        {
            displayProduct(categories, indexOfCategory);
        }
        else
        {
            printf("this Category Isn't Exist\n");
        }
        int indexOfProduct = SearchProduct(ProductName, categories, indexOfCategory);
        if (indexOfProduct ==-1 )
        {
            printf("this Product Isn't Exist\n");
        }

        printf("do you want to display another Catedory's Product ? y/n \n");
    }
}
void displayOrder (Product buyProduct[], int buycount)
{
    int TotalPrice = 0;
    printf("productName  ProductPrice   productQuantity  \n");
    for (int i =0 ; i <buycount ; i++)
    {
        printf("%s \t %d \t\t %d\n",buyProduct[i].ProductName, buyProduct[i].ProductPrice,buyProduct[i].Quantity);

        TotalPrice += buyProduct[i].Quantity * buyProduct[i].ProductPrice;
    }

    printf("the price of All product : %d\n",TotalPrice );
}
void CallMoveProduct (Category **categories, int countCategory)
{
    char categoryName[50],ProductName[50] ;
    displayCategory(categories,countCategory);
    printf("Enter Name Of Category you want to move product from\n");
    scanf("%s", categoryName);
    int indexOfOldCategory = SearchCategory(categoryName, categories, countCategory);
    if(indexOfOldCategory != -1)
    {
        displayProduct(categories, indexOfOldCategory);
        printf ("Enter Name Of Product that Want To move\n");
        scanf("%s", ProductName);
        int indexOfProduct = SearchProduct(ProductName, categories, indexOfOldCategory);
        if (indexOfProduct !=-1 )
        {
            printf ("Enter Name of category that want to move product to it\n");
            scanf("%s", categoryName);
            int indexOfNewCategory = SearchCategory(categoryName, categories, countCategory);
            if (indexOfNewCategory != -1)
            {
                moveProduct(categories,indexOfOldCategory, indexOfNewCategory,indexOfProduct);
                displayProduct(categories, indexOfOldCategory);
                printf("this category is exist");
                displayProduct(categories, indexOfNewCategory);
            }
        }
        else
        {
            printf("this Product Isn't Exist\n");
        }
    }
    else
    {
        printf("this Category Isn't Exist\n");
    }
}
void CallBuyProduct(Category **categories, int countCategory, int *buyCount, Product *productToBuy)
{
    char categoryName[50],ProductName[50] ;
    printf("do you want buy product ? y/n \n");
    while (toupper(getche())=='Y')
    {
        printf("Enter Name Of Category that you want to buy product from\n");
        scanf("%s", categoryName);
        int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
        if(indexOfCategory != -1)
        {
            displayProduct(categories, indexOfCategory);
            printf ("Enter Name Of Product that Want To buy\n");
            scanf("%s", ProductName);
            int indexOfProductBuy = SearchProduct(ProductName, categories, indexOfCategory);
            if (indexOfProductBuy !=-1 )
            {
                buyProduct(categories, indexOfProductBuy,indexOfCategory,buyCount,productToBuy);

                *buyCount+=1;
            }
            else
            {
                printf("Not Exist\n");
            }
        }
        else
        {
            printf("Not Exist\n");
        }
    }
}
void CallUpdateProduct(Category **categories, int countCategory )
{
    char categoryName[50],ProductName[50] ;
    displayCategory(categories,countCategory);
    printf("Enter Name Of Category you want to Update product\n");
    scanf("%s", categoryName);
    int indexOfCategory = SearchCategory(categoryName, categories, countCategory);
    if(indexOfCategory != -1)
    {
        displayProduct(categories, indexOfCategory);
        printf ("Enter Name Of Product that Want To Update\n");
        scanf("%s", ProductName);
        int indexOfProductUpdate = SearchProduct(ProductName, categories, indexOfCategory);
        if (indexOfProductUpdate !=-1 )
        {
            UpdateProduct (indexOfProductUpdate,categories, indexOfCategory);
            displayProduct(categories, indexOfCategory);
        }
        else
        {
            printf("Not Exist\n");
        }
    }
    else
    {
        printf("Not Exist\n");
    }
}
