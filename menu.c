#include "Struct.c"
int MaxSize =20;
int countCategory=0;
void menu ()
{
    char categoryName[50], ProductName[50] ;
    int productQuantity, buyCount =0;
    Category **categories=malloc(MaxSize*sizeof(Category));
    Product *productToBuy=malloc(20*sizeof(Product));
    char key;
    int current =-1 ;
    char *menu[]= {"Add Category","Add Product","Edit Product","Display All Categories","Display Product", "Buy Product", "Move Product","Delete Category","Delete Product","Display Order"};
    gotoxy(20,0);
    SetColor(15);
    printf("Main Menu\n\n");
    for(int i =0 ; i<10; i++)
    {
        gotoxy(20,2+i);
        printf("%s\n",menu[i]);
    }
    while(1)
    {
        key =getch();
        gotoxy(20,0);
        SetColor(15);
        printf("Main Menu\n\n");
        for(int i =0 ; i<10; i++)
        {
            gotoxy(20,2+i);
            printf("%s\n",menu[i]);

        }
        if(key==-32)
        {
            key=getch();
            switch(key)
            {
            case 72:
                current--;
                if (current<0)
                {
                    current= 9;
                }
                gotoxy(20,2+current);
                SetColor(12);
                printf("%s",menu[current]);
                break;
            case 80:
                current++;
                if(current==10)
                {
                    current=0;
                }
                gotoxy(20,2+current);
                SetColor(12);
                printf("%s",menu[current]);
                break;

            }
        }
        else if(key==13)
        {
            switch(current)
            {
            case 0 :
                system("cls");
                printf("enter New Cateogory ? Y/N\n");
                while (toupper(getche())=='Y')
                {
                    printf("\n");
                    AddCategory(categories,&countCategory);
                    printf("enter New Cateogory ? Y/N\n");
                }

                system("cls");
                break;
            case 1 :
                system("cls");
                CallAddProduct(categories, countCategory);
                getche();
                system("cls");
                break;
            case 2 :
                system("cls");
                CallUpdateProduct(categories, countCategory);
                getche();
                system("cls");
                break;
            case 3 :
                system("cls");
                displayCategory(categories,countCategory);
                getche();
                system("cls");
                break;
            case 4 :
                system("cls");
                CallDisplayProduct(categories,countCategory);
                getche();
                system("cls");
                break;
            case 5 :
                system("cls");
                displayCategory(categories,countCategory);
                CallBuyProduct(categories,countCategory,&buyCount,productToBuy);
              //  displayOrder(productToBuy ,buyCount);
                getche();
                Sleep(2);
                system("cls");
                break;
            case 6 :
                system("cls");
                CallMoveProduct(categories,countCategory);
                getche();
                system("cls");
                break;
            case 7 :
                system("cls");
                CallDeleteCategory(categories,&countCategory);
                getche();
                system("cls");
                break;
            case 8 :
                system("cls");
                CallDeleteProduct(categories,countCategory);
                getche();
                system("cls");
                break;
                 case 9 :
                system("cls");
                displayOrder(productToBuy,buyCount);
                getche();
                system("cls");
                break;
            }
        }
    }
}
