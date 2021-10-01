#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
};
struct node *create(struct node *);
struct node *insert(struct node *, int, int);
int display(struct node *);
int polymult(struct node *, struct node *);
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the first polynomial\n");
    head1 = create(head1);
    printf("Enter the second polynomial\n");
    head2 = create(head2);
    polymult(head1, head2);
}
struct node *create(struct node *head)
{
    int n;
    int i;
    int co;
    int ex;
    printf("enter the number of terms\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the co efficient for the term %d\n", i + 1);
        scanf("%d", &co);
        printf("enter the exponent of the term %d\n", i + 1);
        scanf("%d", &ex);
        head = insert(head, co, ex);
    }
    return head;
}
struct node *insert(struct node *head, int co, int ex)
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = co;
    newnode->exp = ex;
    newnode->next = NULL;
    if (head == NULL || ex > head->exp)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exp > ex)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
int display(struct node *head)
{
    if (head == NULL)
    {
        printf("No polynomial.");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d^%d", temp->coeff, temp->exp);
            temp = temp->next;
            if (temp != NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}
int polymult(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = 0;
    if (head1 == 0 || head2 == 0)
    {
        printf("Zero polynomial");
        return -1;
    }
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
        ptr2 = head2;
    }
    printf("multiplying polynomial");
    display(head3);
}