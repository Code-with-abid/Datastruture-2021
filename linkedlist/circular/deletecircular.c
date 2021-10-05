#include<stdio.h>  
#include<stdlib.h>  
void create(int);  
void last_delete();  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void main ()  
{  
    int choice,item;  
    do   
    {  
        printf("1.Append List\n2.Delete Node from end\n3.Exit\n4.Enter your choice?");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            printf("\nEnter the item\n");  
            scanf("%d",&item);  
            create(item);  
            break;   
            case 2:  
            last_delete();  
            break;   
            case 3:  
            exit(0);  
            break;    
            default:  
            printf("\nPlease Enter valid choice\n");  
        }  
                  
    }while(choice != 3);  
}  
void create(int item)    
{    
        
    struct node *ptr = (struct node *)malloc(sizeof(struct node));    
    struct node *temp;  
    if(ptr == NULL)    
    {    
        printf("\nOVERFLOW\n");    
    }    
    else     
    {    
        ptr -> data = item;    
        if(head == NULL)    
        {    
            head = ptr;    
            ptr -> next = head;    
        }    
        else     
        {       
            temp = head;    
            while(temp->next != head)    
                temp = temp->next;    
            ptr->next = head;     
            temp -> next = ptr;     
            head = ptr;    
        }     
    printf("\nNode Inserted\n");  
    }    
                
}   
void last_delete()  
{  
struct node *ptr, *preptr;    
    if(head==NULL)  
    {  
        printf("\nUNDERFLOW\n");  
    }  
    else if (head ->next == head)  
    {  
        head = NULL;  
        free(head);  
        printf("\nNode Deleted\n");  
    }  
    else   
    {  
        ptr = head;  
        while(ptr ->next != head)  
        {  
            preptr=ptr;  
            ptr = ptr->next;  
        }  
        preptr->next = ptr -> next;  
        free(ptr);  
        printf("\nNode Deleted\n");  
    }  
}  
