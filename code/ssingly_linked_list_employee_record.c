#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>
#include <string.h>

struct node_employee_address
{
    char house_number[15], sector_phase[10], street_name[30], ut_state[30], country[30], pincode[7];
};
struct node_employee
{
    char  id[7], employee_name[30], employee_father[30], employee_mother[30], date_joining[12], position[30], department[30];
    struct node_employee_address employee_address;
    struct node *next;
};
typedef struct node_employee LIST;
LIST *start = NULL;
int num=0;

void choices(int);
LIST* new_node();
void create_node();
void insert_node(LIST*);
LIST* insert_userview();
void delete_node(LIST*);
void display_node(LIST*);
void update_node(LIST*);
void search_node(LIST*);
void search_show(LIST*,int);
int remove_duplicate_node(LIST*);
void remove_duplicate_create_node(LIST*);
int validation_id(char[]);
int validation_correction(char[]);
int validation_number(char[],int);

int main()/*Main function*/
{
    int option;
    while(1)
    {
        system("cls");
        printf("\nPROGRAM OF LINKED LIST\n\n");
        printf("1. Create an employee node\n");
        printf("2. Display all employees record\n");
        printf("3. Insert an employee record\n");
        printf("4. Delete an employee record\n");
        printf("5. Update an employee record\n");
        printf("6. Search an employee record\n");
        printf("7. Exit\n");
        printf("Enter the required option: ");
        scanf("%d",&option);
        choices(option);
    }
    return 0;
}
void choices(int option)/*Choice function for switching cases as per input given by main function*/
{
    switch(option)
    {
    case 1:
            create_node();
            break;
    case 2:
            display_node(start);
            break;
    case 3:
            insert_node(start);
            break;
    case 4:
            delete_node(start);
            break;
    case 5:
            update_node(start);
            break;
    case 6:
            search_node(start);
            break;
    case 7:
            exit(0);
    default:
            printf("\nInvalid Option \nPlease enter correct option");
            getch();
            break;
    }
}
LIST* new_node() /*To make nodes only*/
{
    LIST *temp=NULL;
    temp = (LIST *)malloc(sizeof(LIST));
    return temp;
}
void create_node() /*To create new nodes in linked list*/
{
    int v_c=0, v_n=0, v_i=0;
    char ch;
    LIST *temp=NULL, *t=NULL, *k=NULL;
    temp = new_node();
    t = temp;
    do
    {
        fflush(stdin);
        printf("\n\n**************************************************************************************************\n");
        printf("\nEnter Details of Employee:-");CVALUE1:
        printf("\nUnique ID of Employee (Enter 6 digit number only) %d: ",num+1);
        scanf("%s",&temp->id);
        v_i = validation_id(temp->id);if(v_i==1){goto CVALUE1;}CVALUE2:
        fflush(stdin);
        printf("\nEmployee name : ");
        strupr(gets(temp->employee_name));
        v_c  = validation_correction(temp->employee_name); if(v_c==1) {goto CVALUE2;}CVALUE3:
        printf("\nEmployee Father name : ");
        strupr(gets(temp->employee_father));
        v_c  = validation_correction(temp->employee_father); if(v_c==1) {goto CVALUE3;}CVALUE4:
        printf("\nEmployee Mother name : ");
        strupr(gets(temp->employee_mother));
        v_c  = validation_correction(temp->employee_mother); if(v_c==1) {goto CVALUE4;}CVALUE5:
        printf("\nEmployee Date of Joining of Company\n(Date format: dd/mm/yyyy or dd.mm.yyyy): ");
        gets(temp->date_joining);
        v_n = validation_number(temp->date_joining,0); if(v_n==1) {goto CVALUE5;}CVALUE6:
        printf("\nEmployee Position/Rank : ");
        strupr(gets(temp->position));
        v_c  = validation_correction(temp->position); if(v_c==1) {goto CVALUE6;}CVALUE7:
        printf("\nEmployee Department name : ");
        strupr(gets(temp->department));
        v_c  = validation_correction(temp->department); if(v_c==1) {goto CVALUE7;}
        printf("\nEmployee Address :- ");CVALUE8:
        printf("\nHouse number : ");
        gets(temp->employee_address.house_number);
        v_n = validation_number(temp->employee_address.house_number,1); if(v_n==1) {goto CVALUE8;}CVALUE9:
        printf("\nSector/Phase : ");
        gets(temp->employee_address.sector_phase);
        v_n = validation_number(temp->employee_address.sector_phase,1); if(v_n==1) {goto CVALUE9;}CVALUE10:
        printf("\nStreet name : ");
        strupr(gets(temp->employee_address.street_name));
        v_c  = validation_correction(temp->employee_address.street_name); if(v_c==1) {goto CVALUE10;}CVALUE11:
        printf("\nU.T./State : ");
        strupr(gets(temp->employee_address.ut_state));
        v_c  = validation_correction(temp->employee_address.ut_state); if(v_c==1){goto CVALUE11;}CVALUE12:
        printf("\nCountry : ");
        strupr(gets(temp->employee_address.country));
        v_c  = validation_correction(temp->employee_address.country); if(v_c==1) {goto CVALUE12;}CVALUE13:
        printf("\nPincode : ");
        gets(temp->employee_address.pincode);
        v_i = validation_id(temp->employee_address.pincode); if(v_i==1) {goto CVALUE13;}
        FORMATION:
        printf("\nDo you want to add next node (press y/n): ");
        ch = getchar();
        if(ch=='y' || ch=='Y')
        {
            temp->next = new_node();
            temp = temp->next;
        }
        else if(ch!='y' && ch!='Y' && ch!='n' && ch!='N' )
        {
            printf("\nInvalid Character"); goto FORMATION;
        }
        num++;
    }while(ch=='y' || ch=='Y');
    temp->next=NULL;
    if(start==NULL)
        start=t;
    else
    {
        k = start;
        while(k->next!=NULL)
            k = k->next;
        k->next = t;
    }
    remove_duplicate_create_node(start);
    printf("\nTotal number of nodes = %d ",num);
    getch();
}

void display_node(LIST *ptr) /*To display or traverse full linked list*/
{
    printf("\n\n**************************************************************************************************\n");
    if(ptr==NULL)
        printf("\nThe Linked List is empty");
    else
    {
        int show=1;
        printf("\nThe Linked List is as followed:\n");
        while(ptr!=NULL)
        {
            printf("\nEmployee No.     :  %d",show);
            printf("\nEmployee ID      :  %s",ptr->id);
            printf("\nEmployee Name    :  %s",ptr->employee_name);
            printf("\nFather Name      :  %s",ptr->employee_father);
            printf("\nMother Name      :  %s",ptr->employee_mother);
            printf("\nDate of Joining  :  %s",ptr->date_joining);
            printf("\nPosition         :  %s",ptr->position);
            printf("\nDepartment       :  %s",ptr->department);
            printf("\nHouse number     :  %s",ptr->employee_address.house_number);
            printf("\nSector/Phase     :  %s",ptr->employee_address.sector_phase);
            printf("\nStreet name      :  %s",ptr->employee_address.street_name);
            printf("\nUT/State         :  %s",ptr->employee_address.ut_state);
            printf("\nCountry          :  %s",ptr->employee_address.country);
            printf("\nPinCode          :  %s",ptr->employee_address.pincode);
            printf("\n\n**************************************************************************************************\n");
            ptr = ptr->next;
            show+=1;
        }
    }
    getch();
}
void insert_node(LIST *ptr) /*To insert nodes in linked list*/
{
    int opt, v_c=0, v_n=0, v_i=0, i=0;
    LIST *insert_pointer = NULL;
    printf("\n\n**************************************************************************************************\n");
    printf("\n1. Insert an employee entry at beginning of linked list\n");
    printf("2. Insert an employee entry at specific position in linked list\n");
    printf("3. Insert an employee entry at end of linked list\n");
    printf("Enter required option: ");
    scanf("%d",&opt);
    printf("\n\n**************************************************************************************************\n");
    switch(opt)
    {
    case 1:/*inserting a node at beginning of linked list*/
        insert_pointer = insert_userview();
        i = remove_duplicate_node(insert_pointer);
        if(i==0)
        {
            if(start==NULL)
                insert_pointer->next = NULL;
            else
                insert_pointer->next = start;
            start = insert_pointer;
            num+=1;
            printf("\nThe employee entry has been inserted successfully");
        }
        break;
    case 2:/*inserting a node after a specific position in linked list*/
        if(num==0)
            printf("\nFirst create a list");
        else
        {
            int pos;
            printf("\nPlease enter a number greater than 0 and smaller than or equal to: %d",num);
            printf("\nEnter position after which you want to insert a new employee entry : ");
            scanf("%d",&pos);
            if(pos<=0 || pos>num)
                printf("\nInvalid node position");
            else
            {
                int j=1;
                insert_pointer = insert_userview();
                i = remove_duplicate_node(insert_pointer);
                if(i==0)
                {
                    while(j<pos)
                    {
                        ptr = ptr->next;
                        j++;
                    }
                    insert_pointer->next = ptr->next;
                    ptr->next = insert_pointer;
                    num+=1;
                    printf("\nThe employee entry has been inserted successfully");
                }
            }
        }
        break;
    case 3:/*inserting a node at end of linked list*/
        insert_pointer = insert_userview();
        i = remove_duplicate_node(insert_pointer);
        if(i==0)
        {
            insert_pointer->next = NULL;
            if(start==NULL)
                start = insert_pointer;
            else
            {
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = insert_pointer;
            }
            num+=1;
            printf("\nThe employee entry has been inserted successfully");
        }
        break;
    default:
        printf("\nInvalid Option \nPlease enter correct option");
        break;
    }
    if(i==1)
        free(insert_pointer);
    getch();
}
LIST* insert_userview()/*To showcase instructions to user during inserting nodes */
{
    int v_c=0, v_n=0, v_i=0;
    fflush(stdin);
    LIST *temp=NULL;
    temp = new_node();
    printf("\nEnter Details of Employee:-");VALUE1:
    printf("\nUnique ID of Employee (Enter 6 digit number only) %d: ",num+1);
    scanf("%s",&temp->id);
    v_i = validation_id(temp->id); if(v_i==1) {goto VALUE1;}VALUE2:
    fflush(stdin);
    printf("\nEmployee name : ");
    strupr(gets(temp->employee_name));
    v_c  = validation_correction(temp->employee_name); if(v_c==1) {goto VALUE2;}VALUE3:
    printf("\nEmployee Father name : ");
    strupr(gets(temp->employee_father));
    v_c  = validation_correction(temp->employee_father); if(v_c==1) {goto VALUE3;}VALUE4:
    printf("\nEmployee Mother name : ");
    strupr(gets(temp->employee_mother));
    v_c  = validation_correction(temp->employee_mother); if(v_c==1) {goto VALUE4;}VALUE5:
    printf("\nEmployee Date of Joining of Company\n(Date format: dd/mm/yyyy or dd.mm.yyyy): ");
    gets(temp->date_joining);
    v_n = validation_number(temp->date_joining,0); if(v_n==1) {goto VALUE5;}VALUE6:
    printf("\nEmployee Position/Rank : ");
    strupr(gets(temp->position));
    v_c  = validation_correction(temp->position); if(v_c==1) {goto VALUE6;}VALUE7:
    printf("\nEmployee Department name : ");
    strupr(gets(temp->department));
    v_c  = validation_correction(temp->department); if(v_c==1) {goto VALUE7;}
    printf("\nEmployee Address : ");VALUE8:
    printf("\nHouse number : ");
    gets(temp->employee_address.house_number);
    v_n = validation_number(temp->employee_address.house_number,1); if(v_n==1) {goto VALUE8;}VALUE9:
    printf("\nSector/Phase : ");
    gets(temp->employee_address.sector_phase);
    v_n = validation_number(temp->employee_address.sector_phase,1); if(v_n==1) {goto VALUE9;}VALUE10:
    printf("\nStreet name : ");
    strupr(gets(temp->employee_address.street_name));
    v_c  = validation_correction(temp->employee_address.street_name); if(v_c==1) {goto VALUE10;}VALUE11:
    printf("\nU.T./State : ");
    strupr(gets(temp->employee_address.ut_state));
    v_c  = validation_correction(temp->employee_address.ut_state); if(v_c==1) {goto VALUE11;}VALUE12:
    printf("\nCountry : ");
    strupr(gets(temp->employee_address.country));
    v_c  = validation_correction(temp->employee_address.country); if(v_c==1) {goto VALUE12;}VALUE13:
    printf("\nPincode : ");
    gets(temp->employee_address.pincode);
    v_i = validation_id(temp->employee_address.pincode); if(v_i==1) {goto VALUE13;}

    return temp;
}
void delete_node(LIST *ptr) /*To delete node form linked list*/
{
    int opt;
    printf("\n\n**************************************************************************************************\n");
    printf("\n1. Delete an employee entry from beginning of linked list\n");
    printf("2. Delete an employee entry from specific position in linked list\n");
    printf("3. Delete an employee entry from end of linked list\n");
    printf("Enter required option: ");
    scanf("%d",&opt);
    printf("\n\n**************************************************************************************************\n");
    LIST *temp=NULL;
    switch(opt)
    {
    case 1:/*deleting a node from beginning of linked list*/
        if(ptr==NULL)
            printf("\nThe linked list is empty");
        else
        {
            temp = ptr;
            start = temp->next;
            free(ptr);
            num-=1;
            printf("\nThe employee entry has been deleted successfully");
        }
        break;
    case 2:/*deleting a node from specific position in linked list*/
        if(ptr==NULL)
            printf("\nThe Linked List is empty");
        else
        {   fflush(stdin);
            int pos=1 ,v_i=0;
            LIST *del_pointer = ptr;
            char del_id[7];
            printf("\nEnter the ID number of employee : ");
            gets(del_id);
            v_i = validation_id(del_id); if(v_i==1){ return; }
            while(del_pointer!=NULL)
            {
                if(strcmp(del_id,del_pointer->id)==0)
                {
                    if(pos==1)
                        start = start->next;
                    else
                    {
                        for(int i=0;i<pos-1;i++)
                        {
                            temp = ptr;
                            ptr = ptr->next;
                        }
                        temp->next = ptr->next;
                    }
                    free(ptr);
                    num-=1;
                    printf("\nThe employee entry has been deleted successfully");
                    break;
                }
                else
                {
                    printf("\nThere does not exist any employee id : %s\nPlease ensure that you entered correct id number",del_id);
                    break;
                }
                pos+=1;
            }
        }
        break;
    case 3:/*deleting a node from end of linked list*/
        if(ptr==NULL)
            printf("\nThe linked list is empty");
        else
        {
            while(ptr->next!=NULL)
            {
                temp = ptr;
                ptr = ptr->next;
            }
            if(ptr==start)
                start=NULL;
            else
                temp->next=NULL;
            free(ptr);
            num-=1;
            printf("\nThe employee entry has been deleted successfully");
        }
        break;
    default:
        printf("\nInvalid Option \n\tPlease enter correct option");
        break;
    }
    getch();
}
void update_node(LIST *ptr) /*To update node of linked list*/
{
    int i=0, y=0, v_i=0, v_n=0, v_c=0;
    LIST *update_change = ptr;
    printf("\n\n**************************************************************************************************\n");
    if(ptr==NULL)
        printf("\nThe Linked List is empty");
    else
    {
        int pos=1;
        fflush(stdin);
        char up_id[7];
        printf("\nEnter the ID number of employee : ");
        gets(up_id);
        v_i = validation_id(up_id); if(v_i==1){ return; }
        while(ptr!=NULL)
        {
            if(strcmp(up_id,ptr->id)==0)
            {
                int up_opt;
                printf("\n1. Position/Rank");
                printf("\n2. Department");
                printf("\n3. House number");
                printf("\n4. Sector/Phase");
                printf("\n5. Street name");
                printf("\n6. UT/State");
                printf("\n7. Country");
                printf("\nPlease enter required option : ");
                scanf("%d",&up_opt);
                printf("\n\n**************************************************************************************************\n");
                fflush(stdin);
                LIST *updation=NULL;
                updation = new_node();
                if(pos!=1)
                        {
                            for(int i=1;i<pos;i++)
                                update_change = update_change->next;
                        }
                switch(up_opt)
                {
                    case 1:
                        printf("\nEnter Employee New Position/Rank : ");
                        strupr(gets(updation->position));
                        v_c  = validation_correction(updation->position); if(v_c==1) { free(updation); return; }
                        i = remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->position,updation->position);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 2:
                        printf("\nEnter New Department name : ");
                        strupr(gets(updation->department));
                        v_c  = validation_correction(updation->department); if(v_c==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->department,updation->department);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 3:
                        printf("\nEnter New House number : ");
                        gets(updation->employee_address.house_number);
                        v_n = validation_number(updation->employee_address.house_number,1); if(v_n==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->employee_address.house_number,updation->employee_address.house_number);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 4:
                        printf("\nEnter New Sector/Phase : ");
                        gets(updation->employee_address.sector_phase);
                        v_n = validation_number(updation->employee_address.sector_phase,1); if(v_n==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->employee_address.sector_phase,updation->employee_address.sector_phase);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 5:
                        printf("\n\tEnter New Street name : ");
                        strupr(gets(updation->employee_address.street_name));
                        v_c  = validation_correction(updation->employee_address.street_name); if(v_c==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->employee_address.street_name,updation->employee_address.street_name);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 6:
                        printf("\nEnter New UT/State name : ");
                        strupr(gets(updation->employee_address.ut_state));
                        v_c  = validation_correction(updation->employee_address.ut_state); if(v_c==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->employee_address.ut_state,updation->employee_address.ut_state);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    case 7:
                        printf("\nEnter New Country name : ");
                        strupr(gets(updation->employee_address.country));
                        v_c  = validation_correction(updation->employee_address.country); if(v_c==1) { free(updation); return; }
                        i=remove_duplicate_node(updation);
                        if(i==0)
                        {
                            strcpy(update_change->employee_address.country,updation->employee_address.country);
                            printf("\nThe change has been successfully updated"); y=1;
                        }
                        break;
                    default:
                        printf("\nInvalid option");
                        break;
                }
                free(updation);
                break;
            }
            ptr = ptr->next;
            pos+=1;
        }
        if(y==0)
                printf("\nThere does not exist any employee id : %s\nPlease ensure that you entered correct id number",up_id);
    }
    getch();
}
void search_node(LIST *ptr) /*To search values in node*/
{
    printf("\n\n**********************************************************************************************************************************************\n");
    if(ptr==NULL)
        printf("\nThe Linked List is empty");
    else
    {
        int sch_opt;
        printf("\n1. By House number");
        printf("\n2. By Street");
        printf("\n3. By UT/State");
        printf("\n4. By Country");
        printf("\nPlease enter required option : ");
        fflush(stdin);
        scanf("%d",&sch_opt);
        printf("\n\n**********************************************************************************************************************************************\n");
        char user_var[30];
        int show=0,i=0,shn=0;
        fflush(stdin);
        switch(sch_opt)
        {
            case 1:
                printf("\nEnter the House number : ");
                gets(user_var);
                shn = validation_number(user_var,1);
                if(shn==0)
                {
                    while(ptr!=NULL)
                    {
                        show+=1;
                        if(strcmp(ptr->employee_address.house_number,user_var)==0)
                        {
                            search_show(ptr,show);
                            i=1;
                        }
                        ptr = ptr->next;
                    }
                    if(i!=1)
                        printf("\n\t\t<------ There does not exist any House number \"%s\" in list ------>",user_var);
                }
                break;
            case 2:
                printf("\nEnter the Street : ");
                strupr(gets(user_var));
                shn = validation_correction(user_var);
                if(shn==0)
                {
                    while(ptr!=NULL)
                    {
                        show+=1;
                        if(strcmp(ptr->employee_address.street_name,user_var)==0)
                        {
                            search_show(ptr,show);
                            i=1;
                        }
                        ptr = ptr->next;
                    }
                    if(i!=1)
                        printf("\n\t\t<------ There does not exist any Street name \"%s\" in list ------>",user_var);
                }
                break;
            case 3:
                printf("\nEnter the UT/State : ");
                strupr(gets(user_var));
                shn = validation_correction(user_var);
                if(shn==0)
                {
                    while(ptr!=NULL)
                    {
                        show+=1;
                        if(strcmp(ptr->employee_address.ut_state,user_var)==0)
                        {
                            search_show(ptr,show);
                            i=1;
                        }
                        ptr = ptr->next;
                    }
                    if(i!=1)
                        printf("\n\t\t<------ There does not exist any UT/State name \"%s\" in list ------>",user_var);
                }
                break;
            case 4:
                printf("\nEnter the Country : ");
                strupr(gets(user_var));
                shn = validation_correction(user_var);
                if(shn==0)
                {
                    while(ptr!=NULL)
                    {
                        show+=1;
                        if(strcmp(ptr->employee_address.country,user_var)==0)
                        {
                            search_show(ptr,show);
                            i=1;
                        }
                        ptr = ptr->next;
                    }
                    if(i!=1)
                        printf("\n\t\t<------ There does not exist any Country name \"%s\" in list ------>",user_var);
                }
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    }
    getch();
}
void search_show(LIST *sr,int show)/*To showcase/display specifically by search method*/
{
    printf("\nEmployee No.     :  %d",show);
    printf("\nEmployee ID      :  %s",sr->id);
    printf("\nEmployee Name    :  %s",sr->employee_name);
    printf("\nFather Name      :  %s",sr->employee_father);
    printf("\nMother Name      :  %s",sr->employee_mother);
    printf("\nDate of Joining  :  %s",sr->date_joining);
    printf("\nPosition         :  %s",sr->position);
    printf("\nDepartment       :  %s",sr->department);
    printf("\n\n**************************************************************************************************\n");
}
int remove_duplicate_node(LIST *repeat) /*To remove duplicate nodes before insertion*/
{
    int i;
    LIST *ptr=start;
    if(ptr==NULL)
        return i=0;
    else
    {
        while(ptr!=NULL)
        {
            if((strcmp(repeat->id,ptr->id)==0) || ((strcmp(repeat->employee_name,ptr->employee_name)==0) && (strcmp(repeat->employee_father,ptr->employee_father)==0) && (strcmp(repeat->employee_mother,ptr->employee_mother)==0) && (strcmp(repeat->date_joining,ptr->date_joining)==0) && (strcmp(repeat->position,ptr->position)==0) && (strcmp(repeat->department,ptr->department)==0) && (strcmp(repeat->employee_address.house_number,ptr->employee_address.house_number)==0) && (strcat(repeat->employee_address.sector_phase,ptr->employee_address.sector_phase)==0) &&
                   (strcmp(repeat->employee_address.street_name,ptr->employee_address.street_name)==0) && (strcmp(repeat->employee_address.ut_state,ptr->employee_address.ut_state)==0) && (strcat(repeat->employee_address.country,ptr->employee_address.country)==0) && (strcat(repeat->employee_address.pincode,ptr->employee_address.pincode)==0)))
            {
                if(strcmp(repeat->id,ptr->id)==0)
                    {printf("\nThis ID number is already assigned\nPlease enter new id... "); return i=1;}
                else
                    {printf("\nThis Employee entry is already present\nPlease enter new entry... "); return i=1;}
            }
            ptr = ptr->next;
        }
        return i=0;
    }
}
void remove_duplicate_create_node(LIST *repeat) /*To remove/delete duplicate nodes which are formed after create_node function and which are inserted*/
{
    int k=0;
    LIST *check=NULL, *prev=repeat;
    for(int i=1;i<=num;i++)
    {
        check = repeat->next;
        if(check==NULL)
            break;
        for(int j=num-i;j>=1;j--)
        {
            if((strcmp(repeat->id,check->id)==0) || ((strcmp(repeat->employee_name,check->employee_name)==0) && (strcmp(repeat->employee_father,check->employee_father)==0) && (strcmp(repeat->employee_mother,check->employee_mother)==0) && (strcmp(repeat->date_joining,check->date_joining)==0) && (strcmp(repeat->position,check->position)==0) && (strcmp(repeat->department,check->department)==0) && (strcmp(repeat->employee_address.house_number,check->employee_address.house_number)==0) && (strcat(repeat->employee_address.sector_phase,check->employee_address.sector_phase)==0) &&
                   (strcmp(repeat->employee_address.street_name,check->employee_address.street_name)==0) && (strcmp(repeat->employee_address.ut_state,check->employee_address.ut_state)==0) && (strcat(repeat->employee_address.country,check->employee_address.country)==0) && (strcat(repeat->employee_address.pincode,check->employee_address.pincode)==0)))
            {
                    prev->next = check->next;
                    free(check);
                    check = prev->next;
                    num-=1; k+=1;
            }
            else
            {
                prev = check;
                check = check->next;
            }
        }
        repeat = repeat->next;
    }
    if(k!=0)
        printf("\n!!! Duplicate values are removed automatically !!!");
}
int validation_id(char value_id[])/*Validation 1*/
{
    int v_i=0;
    int len = strlen(value_id);
    if(len!=6)
    {
        printf("\nPlease enter 6 digit number");
        getch();
        return v_i=1;
    }
    else
    {
        for(int a=0;a<len;a++)
        {
            if(value_id[a]>=48 && value_id[a]<=57)
                continue;
            else
            {
                printf("\nPlease enter digits only");
                getch();
                return v_i=1;
            }
        }
    }
    return v_i=0;
}
int validation_correction(char value[])/*Validation 2*/
{
    int v_c=0;
    int len = strlen(value);
    for(int b=0;b<len;b++)
    {
        if((value[b]>=65&&value[b]<=90) || (value[b]>=97&&value[b]<=122) || value[b]==46 || value[b]==32)
            continue;
        else
        {
            printf("\nPlease enter alphabets only ");
            getch();
            return v_c=1;
        }
    }
    return v_c=0;
}
int validation_number(char value[],int c)/*Validation 3*/
{
    int v_n=0;
    int len = strlen(value);
    if(c==1)
    {
        for(int d=0;d<len;d++)
        {
            if((value[d]>=48 && value[d]<=57) || value[d]==45 || value[d]==47 || (value[d]>=65&&value[d]<=90) || value[d]==32 || (value[d]>=97&&value[d]<=122))
                continue;
            else
            {
                printf("\nPlease enter valid address number ");
                getch();
                return v_n=1;
            }
        }
        return v_n=0;
    }
    else
    {
        if(len==10)
        {
            for(int d=0;d<len;d++)
            {
                if((value[d]>=48 && value[d]<=57) || (value[2]==46&&value[5]==46) || (value[2]==47&&value[5]==47))
                    continue;
                else
                {
                    printf("\nPlease enter date in valid format ");
                    getch();
                    return v_n=1;
                }
            }
            return v_n=0;
        }
        else
        {
            printf("\nInvalid date added ");
            getch();
            return v_n=1;
        }
    }
}
