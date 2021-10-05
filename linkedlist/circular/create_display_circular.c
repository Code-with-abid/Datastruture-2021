#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
   
 
struct node{  
    int data;  
    struct node *next;  
};  
   

struct node *head = NULL;  
struct node *tail = NULL;  
   
 
void add(int data){  
   
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
   
    if(head == NULL){  
       
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else {  
        
        tail->next = newNode;  
        
        tail = newNode;  
       
        tail->next = head;  
    }  
}  
   

void display(){  
    struct node *current = head;  
    if(head == NULL){  
        printf("List is empty");  
    }  
    else{  
        printf("Nodes of the circular linked list: \n");  
         do{  
             
            printf("%d ", current->data);  
            current = current->next;  
        }while(current != head);  
        printf("\n");  
    }  
}  
      
int main()  
{  
   
   add(1);  
   add(2);  
   add(3);  
   add(4);  
 
   display();  
     
   return 0;  
}  
Output:
