#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        }; 
                     
        
void addNewNode(Node **,Node**,int);
void listAll(Node *);
int lengthOfList(Node *);
Node* create(int);
Node* getNode(Node **);
void returnNode(Node *,Node **);
void delNode(Node **,Node **);  
void push(Node **,int,Node **);
void pop(Node **,Node **);  
void returnAllNode(Node **,Node **);


int main(void){
   
   Node *poolhead=create(10);
   
   
   Node *head=NULL;
   addNewNode(&head,&poolhead,15);
   addNewNode(&head,&poolhead,19);
   addNewNode(&head,&poolhead,24);
   addNewNode(&head,&poolhead,37);
   addNewNode(&head,&poolhead,90);
   listAll(head);
   //delNode(&head,&poolhead);
   //delNode(&head,&poolhead);
   //delNode(&head,&poolhead);
   returnAllNode(&head,&poolhead);
   
   listAll(head);
   
   
   //Node *sp=NULL;
   
   
  /*
   push(&sp,50,&poolhead);
   push(&sp,54,&poolhead);
   push(&sp,31,&poolhead);
   push(&sp,37,&poolhead);
   push(&sp,20,&poolhead);
   push(&sp,18,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);
   pop(&sp,&poolhead);*/
   
   
   
   
   
    system("pause");          
    return 0;
    
}


void addNewNode(Node **ptr,Node **poolhead,int x){
     Node *pNewNode=getNode(poolhead);
     pNewNode->data=x;
     pNewNode->link=NULL;
     
     if((*ptr)==NULL){
     (*ptr)=pNewNode;}
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->link!=NULL){
     pTailNode=pTailNode->link;
     }
     pTailNode->link=pNewNode;
     
     }
     
     
     }
     
void delNode(Node **ptr,Node **poolhead){
     Node *tmp;
     if((*ptr)==NULL)
     cout<<"空串列"<<endl;
     else{
          tmp=*ptr;
          (*ptr)=(*ptr)->link;
          returnNode(tmp,poolhead);
          
          }
          
     }


     
void listAll(Node *ptr){
     while(ptr!=NULL){ 
     cout<<ptr->data<<"  ";
     ptr=ptr->link;
     } 
      
      cout<<endl;
}
     
int lengthOfList(Node *ptr){
    int count=0;
    if(ptr==NULL)
    return 0;
    else{
    while(ptr!=NULL) {
     count++;
     ptr=ptr->link;
     }
     
     return count;
     }
     }
     

     

     
     
Node* create(int n){
       
       Node *ptr,*avail=NULL;
       for(int i=1;i<=n;i++){
               ptr=new Node;
               ptr->link=avail;
               avail=ptr;
               }
               
          return avail;
               
      }
      
Node* getNode(Node **avail){
      Node *p;
      p=*avail;
      
      if(*avail!=NULL)
       *avail=(*avail)->link;
       
       return p;     
      }
      
void returnNode(Node *x,Node **poolhead){
     
     x->link=*poolhead;
     *poolhead=x;
     
     
     }
     
void returnAllNode(Node **head,Node **poolhead){
     
      Node *temp=*head;
      
      while(temp->link!=NULL)
         temp=temp->link;          
         
      temp->link=*poolhead;
      *poolhead=*head;
      *head=NULL;   
                         
     
     }
     
     
     
void push(Node **top,int x,Node **poolhead){
     
     if(*poolhead==NULL)
     cout<<"堆疊已滿"<<endl;
     else{
     Node *newNode=*poolhead;
     *poolhead=(*poolhead)->link;
     newNode->data=x;
     newNode->link=*top;
     *top=newNode;
     cout<<"PUSH進:"<<x<<endl; 
     
     }
     
     }
     
void pop(Node **top,Node **poolhead){
      if((*top)==NULL)
        cout<<"堆疊已空"<<endl;
     else{
        int x;
        Node *ptr;
        ptr=*top;
        x=ptr->data;
        *top=(*top)->link;
        
        ptr->link=*poolhead;
        *poolhead=ptr;
        cout<<"POP出:"<<x<<endl;  
          
          }
     
     }


