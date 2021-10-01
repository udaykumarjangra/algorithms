#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct record
{
    int aadhar_number;
    char name[10];
    char father_name[10];
    char mother_name[10];
    char gender[10];
    int dob;
    struct record *next;
    struct record *previous;
};

struct record *head;
struct record *curr;
struct record *tail;
struct record *start = NULL;

void swap(struct record *a, struct record *b);
void printlist();

struct record *duplicate(int aadhar_number, struct record **prev)
{
    struct record *ptr = head;
    struct record *tmp = NULL;
    bool found = false;

    while (ptr != NULL)
    {
        if (ptr->aadhar_number == aadhar_number)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if (true == found)
    {
        if (prev)
            *prev = tmp;
        return 1;
    }
    else
    {
        return NULL;
    }
}

int checkstring(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] == ' ') || (str1[i] == '.'))
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void create_list()
{
    struct record *ptr = (struct record *)malloc(sizeof(struct record));
    struct record *p = NULL;
    struct record *prev = NULL;
    int u;
    if (NULL == ptr)
    {
        printf("\n Node creation failed \n");
    }
    printf("\nAadhar Number (6 Digit Number) : ");
    scanf("%d", &ptr->aadhar_number);
    if(ptr->aadhar_number > 999999 || ptr->aadhar_number < 100000)
    {
        printf("Only 6-digit Aadhar Number is allowed");
        create_list();
    }
    else
    {
        p = duplicate(ptr->aadhar_number, &prev);
        if(p==1)
        {
            printf("Aadhar Number Already There");
            create_list();
        }
        else
        {
            labelname:
            printf("Name : ");
            scanf("%s", &ptr->name);
            u = checkstring(ptr->name);
            if(u == 0)
            {
                printf("Name can only contain (a-z) and '.'\n");
                goto labelname;
            }
            labelfathername:
            printf("Father name : ");
            scanf("%s", &ptr->father_name);
            u = checkstring(ptr->father_name);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelfathername;
            }
            labelmothername:
            printf("Mother name : ");
            scanf("%s", &ptr->mother_name);
            u = checkstring(ptr->mother_name);
            if(u == 0)
            {
                printf("Mother Name can only contain (a-z) and '.'\n");
                goto labelmothername;
            }
            labelgender:
            printf("Gender (M/F) : ");
            scanf("%s", &ptr->gender);
            strupr(ptr->gender);
            if (strcmp(ptr->gender, "M") == 0)
            {}
            else if(strcmp(ptr->gender, "F") == 0)
            {}
            else
            {
                printf("Gender can only contain M and F\n");
                goto labelgender;
            }
            labeldob:
            printf("DOB(Integer Only)(DDMMYYYY) : ");
            scanf("%d", &ptr->dob);
            if(ptr->dob > 99999999 || ptr->dob < 10000000)
            {
                printf("Only DDMMYYYY format is allowed\n");
                goto labeldob;
            }
            ptr->next = head;
            ptr->previous = tail;
            head = ptr;
        }
    }   
}

void add_to_list()
{
    create_list();
}

struct record *search_in_list(int aadhar_number, struct record **prev)
{
    struct record *ptr = head;
    struct record *tmp = NULL;
    bool found = false;

    while (ptr != NULL)
    {
        if (ptr->aadhar_number == aadhar_number)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if (true == found)
    {
        if (prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

void delete_from_list(int aadhar_number)
{
    struct record *prev = NULL;
    struct record *del = NULL;

    printf("\n Deleting Member wih Aadhar Number = %d from list\n",aadhar_number);

    del = search_in_list(aadhar_number, &prev);
    if (del == NULL)
    {
        printf("\nAadhar Number Not Found\n");
    }
    else
    {
        if (prev != NULL)
            prev->next = del->next;

        if (del == curr)
        {
            curr = prev;
        }
        else if (del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return;
}

void print_specific_record(int aadhar_number)
{
    struct record *prev = NULL;
    struct record *p = NULL;

    p = search_in_list(aadhar_number, &prev);
    if (p == NULL)
    {
        printf("\nAadhar Number Not Found\n");
    }
    else
    printf("\n--------------------------------\n");
    printf("Aadhar Number : %d\n", p->aadhar_number);
    printf("Name : %s\n", p->name);
    printf("Father Name : %s\n", p->father_name);
    printf("Mother Name : %s\n", p->mother_name);
    printf("gender : %s\n", p->gender);
    printf("dob : %d\n", p->dob);
    printf("\n--------------------------------\n");
    return;
}

void update_record(int aadhar_number)
{
    int inp=0,ad=0;
    int u;
    struct record *prev = NULL;
    struct record *p = NULL;

    p = search_in_list(aadhar_number, &prev);
    if (p == NULL)
    {
        printf("\nAadhar Number Not Found\n");
    }
    else
    do{
        printf("\n\t Select record which you want to change");
        printf("\n\t 1.  Name");
        printf("\n\t 2.  Father Name");
        printf("\n\t 3.  Mother Name");
        printf("\n\t 4.  Gender");
        printf("\n\t 5.  Date Of Birth");
        printf("\n\t 6.  EXIT\n\n");
        scanf("\n%d", &inp);
        switch(inp)
        {
        case 1:
            labelupdatename:
            printf("Name : ");
            scanf("%s", &p->name);
            u = checkstring(p->name);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelupdatename;
            }
            break;
        case 2:
            labelupdatefathername:
            printf("Father name : ");
            scanf("%s", &p->father_name);
            u = checkstring(p->father_name);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelupdatefathername;
            }
            break;
        case 3:
            labelupdatemothername:
            printf("Employee's mother name : ");
            scanf("%s", &p->mother_name);
            u = checkstring(p->mother_name);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelupdatemothername;
            }
            break;
        case 4:
            labelupdategender:
            printf("Gender : ");
            scanf("%s", &p->gender);
            strupr(p->gender);
            if (strcmp(p->gender, "M") == 0)
            {}
            else if(strcmp(p->gender, "F") == 0)
            {}
            else
            {
                printf("Gender can only contain M and F\n");
                goto labelupdategender;
            }
            break;
        case 5:
            labelupdatedob:
            printf("DOB  : ");
            scanf("%d", &p->dob);
            if(p->dob > 99999999 || p->dob < 10000000)
            {
                printf("Only DDMMYYYY format is allowed\n");
                goto labelupdatedob;
            }
            break;
        default:
            printf("Enter Correct value");
        }
    }while(inp!=6);
    return;
}

void bubbleSort(struct record *start) 
{ 
    int swapped, i; 
    struct record *ptr1; 
    struct record *lptr = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->aadhar_number > ptr1->next->aadhar_number) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
    printlist();
} 
  
void swap(struct record *a, struct record *b) 
{ 
    int temp = a->aadhar_number; 
    a->aadhar_number = b->aadhar_number; 
    b->aadhar_number = temp; 
} 

void printlist()
{
    struct record *ptr = head;
    while (ptr != NULL)
    {
        printf("\n------------LIST START------------\n");
        printf("Aadhar Number : %d\n", ptr->aadhar_number);
        printf("Name : %s\n", ptr->name);
        printf("Father Name : %s\n", ptr->father_name);
        printf("Mother Name : %s\n", ptr->mother_name);
        printf("Gender : %s\n", ptr->gender);
        printf("DOB : %d\n", ptr->dob);
        ptr = ptr->next;
        printf("\n-------------LIST END-------------\n");
    }
}

void display_by_specific_factor()
{
    int o,k,j,id,i=0,q;
    int re[10];
    char value[10],y[10]; 
    do{  
        printf("\n\t Select record by which you want to display");
        printf("\n\t 1.  Name");
        printf("\n\t 2.  Father Name");
        printf("\n\t 3.  Mother Name");
        printf("\n\t 4.  Gender");
        printf("\n\t 5.  Date Of Joining");
        printf("\n\t 6.  EXIT\n\n");
        scanf("\n%d", &o);
        struct record *ptr = head;
        struct record *tmp = NULL;
        switch(o)
        {
        case 1:
            printf("Name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                id = 0;
                if (strcmp(ptr->name, value) == 0)
                {
                    re[i] = ptr->aadhar_number;
                    ptr = ptr->next;
                    i=i+1;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            if(i!=0)
            {
                for(q=0;q<i;q++)
                {
                    print_specific_record(re[q]);
                }
            }
            else
            {
                printf("No such record found");
            }
            break;
        case 2:
            printf("Father name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->father_name, value) == 0)
                {
                    re[i] = ptr->aadhar_number;
                    i=i+1;
                    break;
                }
                tmp = ptr;
                ptr = ptr->next;
            }
            if(i!=0)
            {
                for(q=0;q<i;q++)
                {
                    print_specific_record(re[q]);
                }
            }
            else
            {
                printf("No such record found");
            }
            break;
        case 3:
            printf("Mother name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->mother_name, value) == 0)
                {
                    re[i] = ptr->aadhar_number;
                    i=i+1;
                    break;
                }
                tmp = ptr;
                ptr = ptr->next;
            }
            if(i!=0)
            {
                for(q=0;q<i;q++)
                {
                    print_specific_record(re[q]);
                }
            }
            else
            {
                printf("No such record found");
            }
            break;
        case 4:
            printf("Gender : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->gender, value) == 0)
                {
                    re[i] = ptr->aadhar_number;
                    i=i+1;
                    break;
                }
                tmp = ptr;
                ptr = ptr->next;
            }
            if(i!=0)
            {
                for(q=0;q<i;q++)
                {
                    print_specific_record(re[q]);
                }
            }
            else
            {
                printf("No such record found");
            }
            break;
        case 5:
            printf("DOB  : ");
            i=0;
            scanf("%d", &j);
            while (ptr != NULL)
            {
                if (ptr->dob == j)
                {
                    re[i] = ptr->aadhar_number;
                    i=i+1;
                    break;
                }
                tmp = ptr;
                ptr = ptr->next;
            }
            if(i!=0)
            {
                for(q=0;q<i;q++)
                {
                    print_specific_record(re[q]);
                }
            }
            else
            {
                printf("No such record found");
            }
            break;
        default:
            printf("Enter Correct value");
        }
    }while(o>0 && o<8);
}

int main()
{
    int n, i, a, y;
    char ch;
    head = NULL;
    printf("Enter the number of members: \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter Record for member: %d",i,"\n");
        create_list();
    }
    
    do{
        printf("\n\t MAIN MENU");
        printf("\n\t1. Add a record");
        printf("\n\t2. Delete a record");
        printf("\n\t3. Search a record");
        printf("\n\t4. Update a record");
        printf("\n\t5. Display all the records");
        printf("\n\t6. Display by Specific Factor");
        printf("\n\t7. Sort by aadhar number");
        printf("\n\t8. EXIT\n\n");
        scanf("\n%d", &y);
        switch(y)
        {
        case 1:
            add_to_list();
            break;
        case 2:
            printf("Enter aadhar number of member you want to delete:");
            scanf("%d",&a);
            delete_from_list(a);
            break;
        case 3:
            printf("Enter aadhar number of member you want to search:");
            scanf("%d",&a);
            print_specific_record(a);
            break;
        case 4:
            printf("Enter aadhar number of member you want to update:");
            scanf("%d",&a);
            update_record(a);
            break;
        case 5:
            printlist();
            break;
        case 6:
            display_by_specific_factor();
            break;
        case 7:
            bubbleSort(head);
            break;
        }
    }while(y!=8);
}
