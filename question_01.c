#include<stdio.h>
#include<string.h>

//function prototype:
void addBook(int isbns[],char titles[][50],float prices[],int quantities[],int *count);
void processSale(int isbns[],char titles[][50],int quantities[],int count);
void generateLowStockReport(int isbns[],char titles[][50],float prices[],int quantities[],int count);

int main(){
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int choice;
    int count=0 ;
    do{
        printf("======welcome to liberty books======\n");
        printf("1. TO ADD NEW BOOKS\n");
        printf("2. TO PROCESS A SALE\n");
        printf("3. TO GENERATE LOW-STOCK REPORT\n");
        printf("4. EXIT\n");
        printf("enter you choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
               
        addBook(isbns,titles,prices,quantities, &count);
            break;
        case 2:
                 // isbn  titles quantities count
        processSale(isbns,titles,quantities, count);
            break;
        case 3:
                              
        generateLowStockReport(isbns,titles,prices,quantities,count);
            break;
            
        case 4:
        printf("exiting program ...........");
            break;
        
        default:
        printf("invalid choice try again!!");
            
        }
    } while(choice != 4);
    

    return 0;
}

//function definitions:

//function definition of add book
void addBook(int isbns[],char titles[][50],float prices[],int quantities[],int *count){
    if(*count >= 100){
        printf("inventory full!!");
        return;
    }
    int isbn;
    printf("enter isbn: ");
    scanf("%d",&isbn);
    //checking for duplicate isbn
    for(int i=0 ; i < *count ; i++){
        if(isbns[i]==isbn){
            printf("error: isbn already exists !!\n");
            return ;
        }
    }
    isbns[*count]=isbn ;
    printf("enter the title of book: ");
    getchar(); 
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';
    
    printf("enter the price of the book: ");
    scanf("%f",&prices[*count]);

    printf("enter the quantity of book: ");
    scanf("%d",&quantities[*count]);

    (*count)++ ;
    printf("book added successfully!!!\n");
}

//function definition to process a sale
void processSale(int isbns[],char titles[][50],int quantities[],int count){
    int isbn,sold ;
    printf("enter isbn sold:");
    scanf("%d",&isbn);
    for(int i=0 ;i<count ; i++){
        if(isbns[i] == isbn){
            printf("enter number of copies sold: ");
            scanf("%d",&sold);
            if(sold>quantities[i]){
                printf("error: not enough stock available!!");
            }else{
                quantities[i] -= sold ;
                printf("sale processed...number of stock available is %d\n",quantities[i]);
                return;
            }
        }
    }
    printf("error: book is not found!!");
}

//function definition to generate low stock report
void generateLowStockReport(int isbns[],char titles[][50],float prices[],int quantities[],int count){
    printf("====low stock report(quantity less than 5)====\n");
    int found =0 ;
    for(int i=0 ;i<count ; i++){
        if(quantities[i] < 5){
            printf("ISBN: %d | TITLE:%s | PRICE: %.2f | QUANTITY: %d \n"
            ,isbns[i],titles[i],prices[i],quantities[i]);
            found = 1 ;
        }
    }
    if(!found){
        printf("no book with low stock!!!");
    }
}