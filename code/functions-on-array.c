#include <stdio.h>

int array[100];

void add_to_end();
void insert_specific(int);
void delete_specific(int);
void update_specific(int);
void maximum_value();
void minimum_value();

int main()
{
    int i, n, y, a;

    printf("\nHow many elements you want to add in the array?\n");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter data for array position = %d\n", i);
        scanf("%d", &array[i]);
    }

    do{
        printf("\n\t MAIN MENU");
        printf("\n\t1. Add an element to array");
        printf("\n\t2. Add an element to a specific location in an array");
        printf("\n\t3. Delete and element from array");
        printf("\n\t4. Update an element in array");
        printf("\n\t5. Find maximum in array");
        printf("\n\t6. Find minimum in array");
        printf("\n\t7. EXIT\n\n");
        scanf("\n%d", &y);
        switch(y)
        {
        case 1:
            add_to_end();
            break;
        case 2:
            printf("Enter the location where you want to add element:\n");
            scanf("%d",&a);
            insert_specific(a);
            break;
        case 3:
            printf("Enter the position where you want to delete from array:\n");
            scanf("%d",&a);
            delete_specific(a);
            break;
        case 4:
            printf("Enter position of element to be updated:\n");
            scanf("%d",&a);
            update_specific(a);
            break;
        case 5:
            maximum_value();
            break;
        case 6:
            minimum_value();
            break;
            }
    }while(y!=7);

return 0;
}

void add_to_end()
{
    int i, count=0;
    for(i=0;i<100;i++)
    {
        if(array[i] != 0)
        count = count + 1;
    }
    
    printf("Enter the value to be added at the end:\n");
    scanf("%d", &array[count]);
    printf("New Array:");
    for (i=0;i<=count;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insert_specific(int a)
{
    int i, j, count=0;
    for(j=0;j<100;j++)
    {
        if(array[j] != 0)
        count = count + 1;
    }
    for (i = count; i >= a; i--) 
        array[i] = array[i - 1];
    
    printf("Enter the value to be inserted at position %d:\n", a);
    scanf("%d", &array[a - 1]);

    printf("New Array:");
    for (i=0;i<=count;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void delete_specific(int a)
{
    int i, j, count=0;
    for(j=0;j<100;j++)
    {
        if(array[j] != 0)
        count = count + 1;
    }

    array[a-1] = 0;
    
    for (i = 0; i <= count - a - 1; i++)
    {
        array[a + i - 1] = array[a + i];
        array[a+i]=0;
    }
    
    for(count=0,j=0;j<100;j++)
    {
        if(array[j] != 0)
        {
            count = count + 1;
        }
    }

    printf("New Array:");
    for (i=0;i<count;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void update_specific(int a)
{
    int i, j, count=0;
    for(j=0;j<100;j++)
    {
        if(array[j] != 0)
        count = count + 1;
    }
    
    printf("Enter the value to be updated at position %d:\n", a);
    scanf("%d", &array[a - 1]);

    printf("New Array:");
    for (i=0;i<count;i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void maximum_value()
{
    int i, j, count=0, max;
    for(j=0;j<100;j++)
    {
        if(array[j] != 0)
        count = count + 1;
    }
    
    max = array[0];
    for (int i = 1; i < count; ++i)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    printf("Maximum value in array is %d \n", max);
}

void minimum_value()
{
    int i, j, count=0, min;
    for(j=0;j<100;j++)
    {
        if(array[j] != 0)
        count = count + 1;
    }
    
    min = array[0];
    for (int i = 1; i < count; ++i)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    printf("Minimum value in array is %d \n", min);
}
