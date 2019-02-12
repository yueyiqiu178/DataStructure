#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        };
        
       
  
 
void push(Node **,int);
void pop(Node **);  
int getTop(Node *);
void listAll(Node *);
  
        
int main(void){
            
    Node *sp=NULL;
    push(&sp,50);
    push(&sp,32);
    push(&sp,28);
    push(&sp,19);
    push(&sp,88);  
    pop(&sp);
    pop(&sp);
    cout<<"頂端元素為:"<<getTop(sp)<<endl;  
      
      
            
      system("pause");    
      return 0;
    
}





void push(Node **top,int x){
     
     Node *newNode=new Node;
     if(newNode==NULL)
     cout<<"沒有足夠的記憶體"<<endl;
     else{
          
     newNode->data=x;
     newNode->link=*top;
     *top=newNode;
     cout<<"PUSH進:"<<x<<endl; 
     }
     
     }
     
void pop(Node **top){
      if((*top)==NULL)
        cout<<"堆疊已空"<<endl;
     else{
        int x;
        Node *ptr;
        ptr=*top;
        x=ptr->data;
        *top=(*top)->link;
        
        free(ptr);
        cout<<"POP出:"<<x<<endl;  
          
          }
     
     }


int getTop(Node *top){
    if(top==NULL)
      return 0;
    else
       return (top->data);
        
    }
    
    
void listAll(Node *top){
     Node *ptr=top;
     while(ptr!=NULL){
     cout<<ptr->data<<" ";
     ptr=ptr->link;
     }
     cout<<endl;
     
     }
