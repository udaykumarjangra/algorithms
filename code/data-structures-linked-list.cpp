#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct address
{
    int home;
    char street[10];
    char city[10];
    char state[10];
    char country[10];
    int pin;
};
struct record
{
    int employee_id;
    char employee_name[10];
    char father_name[10];
    char mother_name[10];
    char rank[10];
    char dept[10];
    int doj;
    struct address add;
    struct record *next;
};

struct record *head;
struct record *curr;

struct record *duplicate(int employee_id, struct record **prev)
{
    struct record *ptr = head;
    struct record *tmp = NULL;
    bool found = false;

    while (ptr != NULL)
    {
        if (ptr->employee_id == employee_id)
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
    printf("\nEmployee's id (6 Digit Number) : ");
    scanf("%d", &ptr->employee_id);
    if(ptr->employee_id > 999999 || ptr->employee_id < 100000)
    {
        printf("Only 6 Digit Employee ID is allowed");
        create_list();
    }
    else
    {
        p = duplicate(ptr->employee_id, &prev);
        if(p==1)
        {
            printf("Employee Already There");
            create_list();
        }
        else
        {
            labelname:
            printf("Employee's Name : ");
            scanf("%s", &ptr->employee_name);
            u = checkstring(ptr->employee_name);
            if(u == 0)
            {
                printf("Employee Name can only contain (a-z) and '.'\n");
                goto labelname;
            }
            labelfathername:
            printf("Employee's father name : ");
            scanf("%s", &ptr->father_name);
            u = checkstring(ptr->father_name);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelfathername;
            }
            labelmothername:
            printf("Employee's mother name : ");
            scanf("%s", &ptr->mother_name);
            u = checkstring(ptr->mother_name);
            if(u == 0)
            {
                printf("Mother Name can only contain (a-z) and '.'\n");
                goto labelmothername;
            }
            labelrank:
            printf("Employee's Rank : ");
            scanf("%s", &ptr->rank);
            u = checkstring(ptr->rank);
            if(u == 0)
            {
                printf("Rank can only contain (a-z) and '.'\n");
                goto labelrank;
            }
            labeldept:
            printf("Employee's Department  : ");
            scanf("%s", &ptr->dept);
            u = checkstring(ptr->dept);
            if(u == 0)
            {
                printf("Department can only contain (a-z) and '.'\n");
                goto labeldept;
            }
            printf("Employee's DOJ(Integer Only) : ");
            scanf("%d", &ptr->doj);
            printf("Address of Employee\n");
            printf("House No : ");
            scanf("%d", &ptr->add.home);
            printf("Street Name : ");
            scanf("%s", &ptr->add.street);
            printf("State Name : ");
            scanf("%s", &ptr->add.state);
            printf("City Name : ");
            scanf("%s", &ptr->add.city);
            printf("Country Name : ");
            scanf("%s", &ptr->add.country);
            printf("Pincode : ");
            scanf("%d", &ptr->add.pin);
            ptr->next = head;
            head = ptr;
        }
    }   
}

void add_to_list()
{
    create_list();
}

struct record *search_in_list(int employee_id, struct record **prev)
{
    struct record *ptr = head;
    struct record *tmp = NULL;
    bool found = false;

    while (ptr != NULL)
    {
        if (ptr->employee_id == employee_id)
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

void delete_from_list(int employee_id)
{
    struct record *prev = NULL;
    struct record *del = NULL;

    printf("\n Deleting Employee wih Employee ID = %d from list\n",employee_id);

    del = search_in_list(employee_id, &prev);
    if (del == NULL)
    {
        printf("\nEmployee Not Found\n");
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

void print_specific_record(int employee_id)
{
    struct record *prev = NULL;
    struct record *p = NULL;

    p = search_in_list(employee_id, &prev);
    if (p == NULL)
    {
        printf("\nEmployee Not Found\n");
    }
    else
    printf("\n--------------------------------\n");
    printf("Employee id : %d\n", p->employee_id);
    printf("Employee Name : %s\n", p->employee_name);
    printf("Father Name : %s\n", p->father_name);
    printf("Mother Name : %s\n", p->mother_name);
    printf("Rank : %s\n", p->rank);
    printf("Department : %s\n", p->dept);
    printf("DOJ : %d\n", p->doj);
    printf("House No : %d\n", p->add.home);
    printf("Street Name : %s\n",p->add.street);
    printf("State : %s\n", p->add.state);
    printf("City : %s\n", p->add.city);
    printf("Country : %s\n", p->add.country);
    printf("Pin No : %d\n", p->add.pin);
    printf("\n--------------------------------\n");
    return;
}

void update_record(int employee_id)
{
    int inp=0,ad=0;
    int u;
    struct record *prev = NULL;
    struct record *p = NULL;

    p = search_in_list(employee_id, &prev);
    if (p == NULL)
    {
        printf("\nEmployee Not Found\n");
    }
    else
    do{
        printf("\n\t Select record which you want to change");
        printf("\n\t 1.  Employee Name");
        printf("\n\t 2.  Father Name");
        printf("\n\t 3.  Mother Name");
        printf("\n\t 4.  Rank");
        printf("\n\t 5.  Department");
        printf("\n\t 6.  Date Of Joining");
        printf("\n\t 7.  Address");
        printf("\n\t 8.  EXIT\n\n");
        scanf("\n%d", &inp);
        switch(inp)
        {
        case 1:
            labelupdatename:
            printf("Employee's Name : ");
            scanf("%s", &p->employee_name);
            u = checkstring(p->employee_name);
            if(u == 0)
            {
                printf("Employee Name can only contain (a-z) and '.'\n");
                goto labelupdatename;
            }
            break;
        case 2:
            labelupdatefathername:
            printf("Employee's father name : ");
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
            labelupdaterank:
            printf("Employee's Rank : ");
            scanf("%s", &p->rank);
            u = checkstring(p->rank);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelupdaterank;
            }
            break;
        case 5:
            labelupdatedept:
            printf("Employee's Department  : ");
            scanf("%s", &p->dept);
            u = checkstring(p->dept);
            if(u == 0)
            {
                printf("Father Name can only contain (a-z) and '.'\n");
                goto labelupdatedept;
            }
            break;
        case 6:
            printf("Employee's DOJ  : ");
            scanf("%d", &p->doj);
            break;
        case 7:
            do{
                printf("\n\t Select record which you want to change");
                printf("\n\t 1. House No.");
                printf("\n\t 2. Street");
                printf("\n\t 3. State");
                printf("\n\t 4. City");
                printf("\n\t 5. Country");
                printf("\n\t 6. Pincode");
                printf("\n\t 7. Back\n");
                scanf("%d",&ad);
                switch(ad)
                {
                case 1:
                    printf("House No : ");
                    scanf("%d", &p->add.home);
                    break;
                case 2:
                    printf("Street No. ");
                    scanf("%s", &p->add.street);
                    break;
                case 3:
                    printf("State Name : ");
                    scanf("%s", &p->add.state);
                    break;
                case 4:
                    printf("City Name : ");
                    scanf("%s", &p->add.city);
                    break;
                case 5:
                    printf("Country Name : ");
                    scanf("%s", &p->add.country);
                    break;
                case 6:
                    printf("Pincode : ");
                    scanf("%d", &p->add.pin);
                    break;
                default:
                    printf("Enter Correct value");
                }
                inp=0;
            }while(ad!=7);
            break;
        default:
            printf("Enter Correct value");
        }
    }while(inp!=8);
    return;
}

void printlist()
{
    struct record *ptr = head;
    while (ptr != NULL)
    {
        printf("\n------------LIST START------------\n");
        printf("Employee id : %d\n", ptr->employee_id);
        printf("Employee Name : %s\n", ptr->employee_name);
        printf("Father Name : %s\n", ptr->father_name);
        printf("Mother Name : %s\n", ptr->mother_name);
        printf("Rank : %s\n", ptr->rank);
        printf("Department : %s\n", ptr->dept);
        printf("DOJ : %d\n", ptr->doj);
        printf("House No : %d\n", ptr->add.home);
        printf("Street Name : %s\n",ptr->add.street);
        printf("State : %s\n", ptr->add.state);
        printf("City : %s\n", ptr->add.city);
        printf("Country : %s\n", ptr->add.country);
        printf("Pin No : %d\n", ptr->add.pin);
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
        printf("\n\t 1.  Employee Name");
        printf("\n\t 2.  Father Name");
        printf("\n\t 3.  Mother Name");
        printf("\n\t 4.  Rank");
        printf("\n\t 5.  Department");
        printf("\n\t 6.  Date Of Joining");
        printf("\n\t 7.  Address");
        printf("\n\t 8.  EXIT\n\n");
        scanf("\n%d", &o);
        struct record *ptr = head;
        struct record *tmp = NULL;
        switch(o)
        {
        case 1:
            printf("Employee's Name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                id = 0;
                if (strcmp(ptr->employee_name, value) == 0)
                {
                    re[i] = ptr->employee_id;
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
            printf("Employee's father name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->father_name, value) == 0)
                {
                    re[i] = ptr->employee_id;
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
            printf("Employee's mother name : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->mother_name, value) == 0)
                {
                    re[i] = ptr->employee_id;
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
            printf("Employee's Rank : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->rank, value) == 0)
                {
                    re[i] = ptr->employee_id;
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
            printf("Employee's Department  : ");
            i=0;
            scanf("%s", &value);
            while (ptr != NULL)
            {
                if (strcmp(ptr->dept, value) == 0)
                {
                    re[i] = ptr->employee_id;
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
        case 6:
            printf("Employee's DOJ  : ");
            i=0;
            scanf("%d", &j);
            while (ptr != NULL)
            {
                if (ptr->doj == j)
                {
                    re[i] = ptr->employee_id;
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
        case 7:
            do{
                printf("\n\t Select record which you want to change");
                printf("\n\t 1. Street");
                printf("\n\t 2. State");
                printf("\n\t 3. City");
                printf("\n\t 4. Country");
                printf("\n\t 5. Pincode");
                printf("\n\t 6. Back\n\n");
                scanf("%d",&k);
                switch(k)
                {
                case 1:
                    printf("Street No. ");
                    scanf("%s", &value);
                    while (ptr != NULL)
                    {
                        if (strcmp(ptr->add.street, value) == 0)
                        {
                            re[i] = ptr->employee_id;
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
                case 2:
                    printf("State Name : ");
                    scanf("%s", &value);
                    while (ptr != NULL)
                    {
                        if (strcmp(ptr->add.state, value) == 0)
                        {
                            re[i] = ptr->employee_id;
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
                    printf("City Name : ");
                    scanf("%s", &value);
                    while (ptr != NULL)
                    {
                        if (strcmp(ptr->add.city, value) == 0)
                        {
                            re[i] = ptr->employee_id;
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
                    printf("Country Name : ");
                    scanf("%s", &value);
                    while (ptr != NULL)
                    {
                        if (strcmp(ptr->add.country, value) == 0)
                        {
                            re[i] = ptr->employee_id;
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
                    printf("Pincode : ");
                    scanf("%d", &j);
                    while (ptr != NULL)
                    {
                        if (ptr->add.pin == j)
                        {
                            re[i] = ptr->employee_id;
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
            }while(k>0 && k<6);
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
    printf("Enter the number of employees: \n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\nEnter Record for employee: %d",i,"\n");
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
        printf("\n\t7. EXIT\n\n");
        scanf("\n%d", &y);
        switch(y)
        {
        case 1:
            add_to_list();
            break;
        case 2:
            printf("Enter employee id of employee you want to delete:");
            scanf("%d",&a);
            delete_from_list(a);
            break;
        case 3:
            printf("Enter employee id of employee you want to search:");
            scanf("%d",&a);
            print_specific_record(a);
            break;
        case 4:
            printf("Enter employee id of employee you want to update:");
            scanf("%d",&a);
            update_record(a);
            break;
        case 5:
            printlist();
            break;
        case 6:
            display_by_specific_factor();
            break;
        }
    }while(y!=7);
}
