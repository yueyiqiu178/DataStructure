#include<iostream>

using namespace std;
struct Node{
       int data;
       Node *llink;
       Node *rlink;
       
};


void addNewNode(Node **,int);
void listAll(Node *);
int lengthOfList(Node *);
void insertAfter(Node *,int,int);
void insertBefore(Node **,int,int);
void deleteNode(Node **,int);
void concat(Node *,Node *,Node **);
void linkRecover(Node *,Node *);
    
int main(void){
    
     
     Node *head=NULL;
     addNewNode(&head,50);
     addNewNode(&head,32);
     addNewNode(&head,21);
     addNewNode(&head,47);
     addNewNode(&head,56);
     addNewNode(&head,97);
     
     Node *ptr=head;
     while(ptr->rlink!=NULL)
     ptr=ptr->rlink;
     
     listAll(head);
     Node *tmp=head->rlink->rlink;
     tmp->rlink=NULL; 
     listAll(head);
     linkRecover(head,ptr);
     listAll(head);
     
     system("pause");
     return 0;
    
}


void linkRecover(Node *head,Node *last){
     
     Node *leftmost=head;
     Node *rightmost=last;
     
             
     while(leftmost->rlink!=NULL&&leftmost->rlink->llink==leftmost)        
      leftmost=leftmost->rlink;
     
     if(leftmost!=rightmost){
        
        while(rightmost!=leftmost->rlink&&rightmost->llink->rlink==rightmost)                     
             rightmost=rightmost->llink;           
        
        if(leftmost->rlink==rightmost)
           rightmost->llink=leftmost;
        else
           leftmost->rlink=rightmost;
                             
                             }
     
     
     }




void addNewNode(Node **ptr,int x){
     Node *pNewNode=new Node;
     pNewNode->data=x;
     pNewNode->llink=NULL;
     pNewNode->rlink=NULL;
     
     if(NULL==(*ptr)){
     (*ptr)=pNewNode;}
     else{
     Node *pTailNode=(*ptr);
     while(pTailNode->rlink!=NULL){
     pTailNode=pTailNode->rlink;
     }
     pTailNode->rlink=pNewNode;
     pNewNode->rlink=NULL;
     pNewNode->llink=pTailNode;
     }
     }
     
     
void listAll(Node *ptr){
     while(ptr!=NULL){ 
     cout<<ptr->data<<"  ";
     ptr=ptr->rlink;
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
     ptr=ptr->rlink;
     }
     
     return count;
     }
     }
     
     
     
void insertAfter(Node *ptr,int x,int y){
     Node *r=ptr->rlink;
     if(ptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else{
        while(ptr->data!=x&&r->rlink!=NULL) {
          ptr=ptr->rlink;
          r=r->rlink;}
          if(ptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=ptr->rlink;
          pNewNode->llink=ptr;
          ptr->rlink->llink=pNewNode;
          ptr->rlink=pNewNode;}
          else if(r->data==x){
               Node *pNewNode=new Node;
               pNewNode->data=y;
               pNewNode->rlink=NULL;
               pNewNode->llink=r;
               r->rlink=pNewNode;
               }
          else
               cout<<"找不到該節點"<<endl; 
               
               
          }
     
     
     }

void insertBefore(Node **ptr,int x,int y){
     Node *r;
     Node *newptr=*ptr;
     Node *k=*ptr;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=newptr;
          pNewNode->llink=NULL;
          newptr->llink=pNewNode;
          *ptr=pNewNode;
          
          }
     else{
        while(k->data!=x&&k->rlink!=NULL){ 
          r=k;
          k=k->rlink;}
          
          if(k->data==x){
          Node *pNewNode=new Node;
          pNewNode->data=y;
          pNewNode->rlink=k;
          pNewNode->llink=r;
          r->rlink=pNewNode;
          r->llink=pNewNode;
          }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     }
     
  void deleteNode(Node **ptr,int x){
       Node *r;
       Node *newptr=*ptr;
       Node *s=(*ptr)->rlink;
     if(newptr==NULL)
        cout<<"此串列為空串列,找不到該節點"<<endl;
     else if(newptr->data==x){
          
          (*ptr)=(*ptr)->rlink;
           (*ptr)->llink=NULL;       
          }   
     else{
        while(newptr->data!=x&&s->rlink!=NULL){ 
             r=newptr;
             newptr=newptr->rlink;
             s=s->rlink;
          }
          
          if(newptr->data==x){
            r->rlink=newptr->rlink;
            newptr->rlink->llink=r;
            newptr->rlink==NULL;
            newptr->llink==NULL;
          }
          else if(s->data==x){
            s->llink==NULL;
            newptr->rlink=NULL;   
               
               }
          else
               cout<<"找不到該節點"<<endl; 
                   
          }    
     
     
     
     }   
