#include<stdio.h>
#include<string.h>
typedef struct book
{
    char name[100];
    char writer[100];
    int year;
    int page_num;
    double price;
}book;

int main ()
{
    int size,i;
    FILE *fptr;
    fptr=fopen("books.txt", "a+");
    if(fptr==NULL) //dosyanın açılıp açılmadığını kontrol ediyoruz
    {
        printf("DOSYA AÇILAMADI!!!");
    }
    printf("how many books in this library?: ");
    scanf("%d" , &size);
    getchar();
    book  books[size]; //size boyutunda book structına ait books dizisi oluşturuyoruz.
    for(i=0; i<size; i++)
    {
        printf("Enter the book #%d's name: ",i+1);
        fgets(books[i].name, 100, stdin);
        books[i].name[strcspn(books[i].name, "\n")]=0;
        printf("Enter the book #%d's writer's name: ",i+1);
        fgets(books[i].writer, 100, stdin);
        books[i].writer[strcspn(books[i].writer, "\n")]=0;
        printf("Enter the book #%d's page number: ",i+1);
        scanf("%d", &books[i].page_num);
        printf("Enter the book #%d's publishing year: ",i+1);
        scanf("%d", &books[i].year);
        printf("Enter the book #%d's price: ",i+1);
        scanf("%lf", &books[i].price);
        getchar(); // ' ' ile veri kaymasını önlüyoruz 
        fprintf(fptr, "%-20s %-20s %-10d %-10d %-10.2lf\n", books[i].name, books[i].writer, books[i].page_num, books[i].year, books[i].price);
    }
    
    fclose(fptr);
    return 0;
} // This project will continue...
