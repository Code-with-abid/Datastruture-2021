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
void insertatbegin();
void insertatmiddle();
void insertatend();

void main()
{
    head=NULL;
    last=NULL;
    int ch;
    while(1)
    {
        printf("\n\tMAIN MENU:\t\n");
        printf("\n1.Createlist\n2.Display from first\n3.Display from last\n4.Insert at Begin\n5.Insert at Middle\n6.Insert at Last\n7.Exit");
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
                printf("Inserting at the beginning of the list.");
                insertatbegin();
                break;
            }
        case 5:
            {
                printf("Inserting at the middle of the list.");
                insertatmiddle();
                break;
            }
        case 6:
            {
                printf("Inserting at the end of the list.");
                insertatend();
                break;
            }
        case 7:
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
void insertatbegin()
{
    struct node*newnode;
    int data;
    printf("\nEnter the data:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    head->prev=newnode;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}
void insertatmiddle()
{
    struct node *newnode,*temp;
    int data,i=0,n;
    printf("\n Enter the data:");
    scanf("%d",&data);
    printf("\n Enter the position where the data is to be inserted:");
    scanf("%d",&n);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp=head;
    while(i<n-2)
    {
            temp=temp->next;
            i++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;

}
void insertatend()
{
    struct node*temp,*newnode;
    int data;
    printf("\nEnter the data:");
    scanf("%d",&data);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
}
