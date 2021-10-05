#include <stdio.h>  
   
  
struct node{  
    int data;  
    struct node *next;  
};      
   

struct node *head, *tail = NULL;  
   
  
void addNode(int data) {  
       struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
   
    if(head == NULL) {  
        
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        
        tail->next = newNode;  
       
        tail = newNode;  
    }  
}  
   
 
int countNodes() {  
    int count = 0;  
    
    struct node *current = head;  
      
    while(current != NULL) {  
        
        count++;  
        current = current->next;  
    }  
    return count;  
}  
      
 
void display() {  
     
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of singly linked list: \n");  
    while(current != NULL) {  
        
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
      
   
    display();  
      
   
    printf("Count of nodes present in the list: %d", countNodes());  
   
    return 0;  
}  
