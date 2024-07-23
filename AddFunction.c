#include "Struct.c"
void AddCategory(Category **categories,int *countCategory )
{
    Category *category=malloc(sizeof(Category));
    category->Prodectcount=0;
    category->maxProduct=20;
    category->Product=malloc(category->maxProduct*sizeof(Product));
    printf("Enter CategoryName :\n");
    scanf("%s", category->CategoryName);
    categories[*countCategory]=category;
    *countCategory+=1;
    printf("enter new Product ? Y/N\n");
    while (toupper(getche())=='Y')
    {
        printf("\n");
        AddProduct(categories,*countCategory-1);
        printf("enter another Product ? Y/N\n");
    }
}
void AddProduct(Category **category,int indexOfCategory)
{
    Product *product = malloc(1*sizeof(product));
    if(category[indexOfCategory]->Prodectcount< category[indexOfCategory]->maxProduct)
    {
        int validID=0 ;
        printf("enter new productName\n");
        scanf("%s", product->ProductName);

        printf("Enter The Product Price: \n");
        int isValidPrice=scanf("%d",&product->ProductPrice);
        while(isValidPrice==0||product->ProductPrice<1)
        {
            if(isValidPrice==0)
            {
                printf("Enter ProductPrice (only Positive Number):\n");
                while (getchar() != '\n');
                {
                    isValidPrice = scanf("%d",&product->ProductPrice);
                }
            }
            else
            {
                if(product->ProductPrice<1)
                {
                    printf("Enter ProductPrice (only Positive Number):\n");
                    isValidPrice = scanf("%d",&product->ProductPrice);
                }
            }
        }
        printf("Enter The Product Quantity: \n");
        int isValid=scanf("%d",&product->Quantity);
        while (isValid == 0 || product->Quantity < 1)
        {
            if (isValid == 0)
            {
                printf("Enter Quantity (only Positive Number): \n");
                while (getchar() != '\n');

                {
                    isValid = scanf("%d", &product->Quantity);
                }
            }
            else
            {
                if (product->Quantity< 1)
                {
                    printf("Enter Quantity (only Positive Number): \n");
                    isValid = scanf("%d", &product->Quantity);
                }
            }
        }
        category[indexOfCategory]->Product[category[indexOfCategory]->Prodectcount]= *product;
        category[indexOfCategory]->Prodectcount+=1;
    }
    /*
    else
    {
        category->Product = ReSizeProduct();
        printf ("enter new prodectPrice\n");
        scanf("%d\n", &product->ProductPrice);
        printf("enter new prodectName\n");
        scanf("%s\n", product->ProductName);
        printf("enter new prodectQuantity\n");
        scanf("%d", &product->Quantity);
    }
    */
}

