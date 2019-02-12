#include<iostream>

using namespace std;

struct Node{
        
     int data;   
     Node* link;   
        }; 
void addNewNode(Node **,int);
void listAll(Node *);
int lengthOfList(Node *);
void insertAfter(Node *,int,int);
void insertBefore(Node **,int,int);
void deleteNode(Node **,int);
void reverse(Node **head);
Node* addList(Node *,Node *);

int main(void){
   
    Node *head1=NULL;
    Node *head2=NULL;
    Node *head3=NULL;
    
    addNewNode(&head1,9);
    addNewNode(&head1,0);      
    addNewNode(&head1,1);
    addNewNode(&head1,8);
    addNewNode(&head1,5);
    
    addNewNode(&head2,3);
    addNewNode(&head2,4);
    addNewNode(&head2,4);
    addNewNode(&head2,8);
    addNewNode(&head2,6);
     
    head3=addList(head1,head2);
    
    listAll(head3);
    
    system("pause");         
    return 0;
    
}


Node* addList(Node *p,Node *q){
     
        Node *head,*tail,*ptr;
        head=tail=new Node;
        int carry=0,sum;
        int pdigit,qdigit;
        
        while(p!=NULL||q!=NULL||carry!=0){
            if(p==NULL)                              
               pdigit=0;
            else{
                 pdigit=p->data;p=p->link;
                 }                              
            if(q==NULL)                              
               qdigit=0;
            else{
                 qdigit=q->data;q=q->link;
                 }
            sum=pdigit+qdigit+carry;
            tail->link=new Node;
            tail=tail->link;
            tail->data=sum%10;
            carry=sum/10;                                                   
                                          }
     
               tail->link=NULL;
               ptr=head->link;
               free(head);
               return ptr;
     }




void addNewNode(Node **ptr,int x){
     Node *pNewNode=new Node;
     pNewNode->data=x;
     pNewNode->link=NULL;
     
     if(NULL==(*ptr)){
     (*ptr)=pNewNode;}
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->link!=NULL){
     pTailNode=pTailNode->link;
     }
     pTailNode->link=pNewNode;
     
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
     
void insertAfter(Node *ptr,int x,int y){
     if(ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else{
        while(ptr->data!=x&&ptr->link!=NULL) 
          ptr=ptr->link;
          
          if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=ptr->link;
          ptr->link=pNewNode;}
          else
               cout<<"找不到該節點"<<endl; 
               
               
          }
     
     
     }
     
     
void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=*ptr;
          *ptr=pNewNode;
          
          }
     else{
        while(newptr->data!=x&&newptr->link!=NULL){ 
          r=newptr;
          newptr=newptr->link;}
          
          if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->link=r->link;
          r->link=pNewNode;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     }
 
void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          
          (*ptr)=(*ptr)->link;
                  
          }   
     else{
        while(newptr->data!=x&&newptr->link!=NULL){ 
          r=newptr;
          newptr=newptr->link;}
          
          if(newptr->data==x){
            r->link=newptr->link;
            newptr->link==NULL;
            newptr=r->link;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     
     
     
     }
 
     
     
void reverse(Node **head){
      Node *ptr,*tmp;
      ptr=(*head);
      tmp=NULL;
      while(ptr->link!=NULL){
           (*head)=ptr->link;          
              ptr->link=tmp;
              tmp=ptr;
              ptr=(*head);              
                             }
        ptr->link=tmp;                     
      
     
     }
