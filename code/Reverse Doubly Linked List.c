# include<stdio.h>
# include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node *head) {
    struct node *p1 = head;
    while (p1 != NULL) {
        printf("%d ", p1->data);
        p1 = p1->next;
    }
    printf("\n");
}
struct node *insert_node_end(int data, struct node *head)
{
    struct node *temp, *p=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
    return head;
}
struct node* reverse(struct node* head)
{
    struct node* temp;
    while(head->next!=NULL)
    {
        temp=head->next;
        head->next=head->prev;
        head->prev=temp;
        head=head->prev;
    }
    head->next=head->prev;
    head->prev=NULL;
    return head;
}
int main()
{
    int n, i;
    struct node *head=NULL;
    printf("Enter the number of nodes you want to enter\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int info;
        printf("Enter the data you want to enter\n");
        scanf("%d",&info);
        head=insert_node_end(info,head);
    }
    printf("Values in doubly linked list before reversing\n");
    display(head);
    head=reverse(head);
    printf("Values in doubly linked list after reversing\n");
    display(head);
}