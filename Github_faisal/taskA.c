#include<stdio.h>
#include<string.h>

void list();
void View(int *a);
void Insert(int *a);
void search(int *a);
void del(int *a);
void sort_a(int *a);
void sort_d(int *a);
void MemLoc(int *a);
void perform(int *a);
void clear_screen();

int i, j, cm, n = 0;

int main()
{
    int *arr = malloc(100000 * sizeof(int)); //dynamic memory allocation

    while(1)
    {
        list();

        printf("Please, enter a valid keyword from the given list: ");
        scanf("%d", &cm);

        if(cm == 0)
            break;

        perform(arr);
        clear_screen();
    }

    printf("\nThank you for using this system! :)\n");

    return 0;
}

void list()
{
    printf("0.  Exit\n");
    printf("1.  View all elements\n");
    printf("2.  Insert new element\n");
    printf("3.  Search an element\n");
    printf("4.  Delete an element\n");
    printf("5.  Sort elements in ascending order\n");
    printf("6.  Sort elements in descending order\n");
    printf("7.  Find memory location of an element\n");
}

void View(int* ar)
{
    printf("Current elements are: ");
    for(i=1; i<=n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}

void Insert(int* ar)
{
    printf("Please, enter a integer type data to be inserted: ");
    int x;
    scanf("%d", &x);
    ar[++n] = x;
    printf("%d is inserted successfully!\n", ar[n]);
}

void search(int* ar)
{
    printf("Enter a data to be searched: ");
    int x;
    scanf("%d", &x);
    for(i=1; i<=n; i++)
    {
        if(x==ar[i])
        {
            printf("%d is found.\n", x);
            return;
        }
    }
    printf("%d is not found!\n", x);
}

void del(int* ar)
{
    printf("Enter a data to be deleted: ");
    int x, idx = 0;
    scanf("%d", &x);
    for(i=1; i<=n; i++)
    {
        if(x==ar[i])
        {
            idx = i;
            n--;
            break;
        }
    }
    if(idx)
    {
        for(i=idx; i<=n; i++)
        {
            ar[i] = ar[i+1];
        }
        printf("%d is deleted successfully!\n", x);
    }
    else
        printf("%d is not found!\n", x);
}

void sort_a(int* ar)
{
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(ar[i]>ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Elements are sorted in ascending order!\n");
}

void sort_d(int* ar)
{
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(ar[i]<ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("Elements are sorted in descending order!\n");
}

void MemLoc(int* ar)
{
    printf("Enter the index for what you want to know memory location: ");
    int x;
    scanf("%d", &x);
    if(x<1 || x>n)
        printf("Sorry! No such index is present!\n");
    else
        printf("Desired memory location is = %d\n", ar+x+1);
}

void perform(int* ar)
{
    printf("\n");
    if(cm<1 || cm>7)
        printf("Sorry! You entered an invalid keyword!\n");
    else if(cm==1)
        View(ar);
    else if(cm==2)
        Insert(ar);
    else if(cm==3)
        search(ar);
    else if(cm==4)
        del(ar);
    else if(cm==5)
        sort_a(ar);
    else if(cm==6)
        sort_d(ar);
    else if(cm==7)
        MemLoc(ar);
    printf("\n");
}

void clear_screen()
{
    char ch = getchar();
    printf("Press any key to clear screen: ");
    char chh = getchar();
    system("CLS");
}
