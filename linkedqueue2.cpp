#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        };
        
struct queue{
       
     Node *front;
     Node *rear;  
       
       }; 
       
       
 
void enqueue(Node **,Node **,int); 
int dequeue(Node **,Node **); 
void listAll(Node *);
       
       
int main(void){
    
    
      Node *front=NULL;
      Node *rear=NULL;    
      enqueue(&front,&rear,50);
      enqueue(&front,&rear,32);
      enqueue(&front,&rear,48);
      enqueue(&front,&rear,11);
      enqueue(&front,&rear,20);
      enqueue(&front,&rear,98);
      listAll(front);

    
  
      system("pause");         
      return 0;
    
}






void enqueue(Node **front,Node **rear,int x){
     
     Node *newNode=new Node;
     newNode->data=x;
     newNode->link=NULL;
     
     if(*front==NULL)
       *front=newNode;
     else
       (*rear)->link=newNode;
     
       *rear=newNode; 
     
     
     }
     

int dequeue(Node **front,Node **rear){
    
      if(*front==NULL)
       return 0;
       else{
          Node *ptr;
          int x=(*front)->data;
          ptr=*front;
          *front=(*front)->link;
          
          if((*front)==NULL)
            (*rear)=NULL;
          
          free(ptr);
          return x;
            
            
            
            }
    
    
    }
    
    
void listAll(Node *front){
     
     Node *ptr;
     ptr=front;
     while(ptr!=NULL){
          cout<<ptr->data<<" ";               
          ptr=ptr->link;               
                         }
                         
     cout<<endl;
     
     
     
     
     }
