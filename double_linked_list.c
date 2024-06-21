#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record{
	char rollno[10];
	char name[20];
	int sem;
	char branch[4];
	struct record *next;
	struct record *prev;
};
typedef struct record list;
list *first, *last, *pointer, *start1, *temp;
int node_check=0;
int main(){
	int choice, count;
	char roll[8], pos[8];
	list *node;
	while(1)
	{
		printf("Student Database\n");
		printf("\n1.Enter new record\n2.Delete record\n3.Search any record\n4.View all records\n5.Exit\n");
		printf("Choose any option:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:	if(node_check==0){
								system("cls");
								node=(list *)malloc(sizeof(list));
								first=node;
								last=node;
								printf("\nEnter Roll Number of student: ");
								scanf("%s",node->rollno);
								fflush(stdin);
								printf("\nEnter Name of student: ");
								scanf("%s",node->name);
								fflush(stdin);
								printf("\nEnter Branch of student: ");
								scanf("%s",node->branch);
								fflush(stdin);
								printf("\nEnter Semester of student: ");
								scanf("%d",&node->sem);
								node_check=1;
								node->next=NULL;
								node->prev=NULL;
								printf("Press Enter to Continue\n");
								printf("Node is %p",node);
								printf("\nStart is %p",first);
								getch();
								system("cls");
							}
					else{		
								node->next = (list *)malloc(sizeof(list));
								node->next->prev=node;
								node=node->next;
								last=node;
								node->next=NULL;
								system("cls");
								printf("Node is %p\n",node);
								printf("\nEnter Roll Number of student: ");
								scanf("%s",node->rollno);
								fflush(stdin);
								printf("\nEnter Name of student: ");
								scanf("%s",node->name);
								fflush(stdin);
								printf("\nEnter Branch of student: ");
								scanf("%s",node->branch);
								fflush(stdin);
								printf("\nEnter Semester of student: ");
								scanf("%d",&node->sem);
								printf("Press Enter to Continue\n");
								printf("Node is %p",node);
								printf("\nStart is %p",first);
								getch();
								system("cls");				
					}
					break;
					
			case 2:	start1=first;
					if(node_check==0)
					{	system("cls");
						printf("List is Empty\n");
					}
					else{
					printf("Enter roll number of record to delete\n");
					scanf("%s",pos);
					while(start1)
					{	if( !strcmp(pos,start1->rollno) && node_check==1 && start1->prev==NULL && start1->next==NULL)
						{	temp=start1;
							first=start1->next;
							free(temp);
							first=NULL;
							last=NULL;
							node_check=0;
							break;
						}
					
						else if( !strcmp(pos,start1->rollno) && node_check==1 && start1->prev==NULL)
						{	temp=start1;
							first=start1->next;
							free(temp);
							break;
						}
						
						else if(!strcmp(pos,start1->rollno) &&start1->next==NULL)
						{	temp=start1;
							start1=start1->prev;
							start1->next=NULL;
							last=start1;
							free(temp);
							
						}
						else if(!strcmp(pos,start1->rollno)) {
							start1=start1->prev;
							temp=start1;
							start1->next=start1->next->next;
							free(temp);
						}
						start1=start1->next;
					}
					
					printf("Record deleted\nPress Enter to continue\n");
					}
					getch();
					system("cls");
					break;
					
			case 3:	start1=first;
					system("cls");
					printf("Enter roll number of student to search\n");
					fflush(stdin);
					scanf("%s",roll);
					while(start1)
					{
						if(!strcmp(roll,start1->rollno))
						{
							printf("Record found!\n");
							printf("Roll Number: %s \nName: %s \nBranch: %s \nSemester: %d\n",start1->rollno, start1->name, start1->branch, start1->sem);
						}
						start1=start1->next;
					}
					printf("\nPress Enter to Continue\n");
					getch();
					system("cls");
					break;
					
			
			case 4:	start1=first;
					if(node_check==0)
					{	system("cls");
						printf("List is Empty\n");
					}
					else{
					system("cls");
					printf("Node is %p",node);
					printf("\nStart is %p\n",first);
					printf("Roll\t\tName\t\tBranch\tSemester\n");
					while(start1)
					{
					printf("%s\t\t%s\t\t%s\t%d\n",start1->rollno, start1->name, start1->branch, start1->sem);
					start1=start1->next;
					}
					
					}
					printf("Press Enter to continue\n");
					getch();
					system("cls");
					break;
					
			case 5:	exit(0);
					break;
					
			}
	}
	
}
