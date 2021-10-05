#include <stdio.h>  
   

struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
 
struct node *head, *tail = NULL;  
     
void addNode(int data) {  
    
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    
    if(head == NULL) {  
        
        head = tail = newNode;  
          
        head->previous = NULL;  
       
        tail->next = NULL;  
    }  
    else {  
       
        tail->next = newNode;  
         
        newNode->previous = tail;  
         
        tail = newNode;  
         
        tail->next = NULL;  
    }  
}  
   
  
void display() {  
      
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL) {  
        
        printf("%d ", current->data);  
        current = current->next;  
    }  
}  
   
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
    addNode(5);  
      
    //Displays the nodes present in the list  
    display();  
   
    return 0;  
    }  
