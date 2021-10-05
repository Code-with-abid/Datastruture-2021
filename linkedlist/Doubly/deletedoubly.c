#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head,*last;

void createlist();
void displayfromfirst();
void displayfromlast();
void deleteatbegin();
void deleteatmiddle();
void deleteatend();
void deleteentirelist();

void main()
{
    head=NULL;
    last=NULL;
    int ch;
    while(1)
    {
        printf("\n\tMAIN MENU:\t\n");
        printf("\n1.Createlist\n2.Display from first\n3.Display from last\n4.Delete at Begin\n5.Delete at Middle\n6.Delete at Last\n7.Delete Entire List\n9.Exit");
        printf("\nEnter Your Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Creation of list.");
                createlist();
                break;
            }
        case 2:
            {
                printf("Display of list from first.");
                displayfromfirst();
                break;
            }
        case 3:
            {
                printf("Display of list from last.");
                displayfromlast();
                break;
            }
        case 4:
            {
                printf("Delete at the beginning of the list.");
                deleteatbegin();
                break;
            }
        case 5:
            {
                printf("Delete at the middle of the list.");
                deleteatmiddle();
                break;
            }
        case 6:
            {
                printf("Delete at the end of the list.");
                deleteatend();
                break;
            }
        case 7:
            {
                printf("Delete the entire list.");
                deleteentirelist();
                break;
            }
        case 8:
            {
                exit(0);
                break;
            }
        default:
            {
                printf("Wrong choice.");
                break;
            }
        }
    }
}

void createlist()
{
    int data,i,n;
    struct node*newnode;
    printf("Enter the number of node:");
    scanf("%d",&n);
    head=(struct node*)malloc(sizeof(struct node));
    if (head==NULL)
    {
        printf("Memory Allocation Not Possible!");
    }
    else
    {
        printf("Enter data:");
        scanf("%d",&data);
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        last=head;
    }
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if (newnode==NULL)
        {
            printf("Memory Allocation Not Possible!");
        }
        else
        {
            printf("Enter Data:");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
        }
    }

}

void displayfromlast()
{

struct node*temp;
temp=last;
if(head==NULL)
    printf("No Data in List.");
else
{
    while(temp!= NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->prev;
    }
}
}
void displayfromfirst()
{
struct node*temp;
temp=head;
if(head==NULL)
    printf("No Data in List.");
else
  {
    while(temp!= NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
  }
}
void deleteatbegin()
{
    struct node*temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteatmiddle()
{
 struct node *current;
    int i,position;
    printf("Enter the position which is to be deleted:");
    scanf("%d",&position);
    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteatbegin();
    }
    else if(current == last)
    {
        deleteatend();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
void deleteatend()
{
    struct node*temp;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
}
void deleteentirelist()
{
   struct node*temp;
    if(head==NULL)
      printf("No Data in List.");
    else
    {
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            temp->next=NULL;
            free(temp);
        }

    }
}
